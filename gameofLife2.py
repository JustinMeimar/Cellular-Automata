from random import random
import numpy as np
import random
class Cell:
    def __init__(self, life, coords):
        self.life = life
        self.next = None
        self.coords = coords
        self.neighbours = []

    def __str__(self):
        string = ""
        string += (str(self.life) + " coords:" + str(self.coords) + " next:" +str(self.next))
        return string

class Grid:
    def __init__(self, sq_len, start):
        self.sq_len = sq_len
        meta = []
        for y in range(sq_len):
            holder = [Cell(0,(y,x)) for x in range(sq_len)]
            meta += [holder]

        self.grid = np.array(meta)       
      

        for tup in start:
            my_cell = Cell(1, coords=tup)
            
            self.grid[tup[0]][tup[1]] = my_cell

        self.set_coords()
        for i in range(10):
            self.scan()
        
        

    def set_coords(self):
        for x in range(len(self.grid)-1):
         
            for y in range(len(self.grid)):
                self.grid[x][y].coords = (x,y)
               
               

    def find_neighbours(self, cell):
        neighbours = []
        for i in range(-1,2):
            for j in range(-1,2):
                if i == 0 and j == 0:
                    # print('self')
                    pass

                else:
                    # temp = self.grid[cell.coords[0]+i][cell.coords[1]+j]

                    x_pos = cell.coords[0] + i
                    y_pos = cell.coords[1] + j
                    if x_pos >= 0 and x_pos < self.sq_len and y_pos >= 0 and y_pos < self.sq_len:
                        self.grid[x_pos][y_pos].coords = (x_pos, y_pos)
                        n_cell = self.grid[x_pos][y_pos]
                        neighbours.append(n_cell)

        return neighbours
    
    def scan(self):

        for row in self.grid:
            for cell in row:
                # scanning state:
                alive = 0
                dead = 0

                if cell.next != None:
                    cell.life = cell.next
                    cell.next = None

                cell.neighbours = self.find_neighbours(cell)
                # print(len(cell.neighbours), "-"*40, cell, "*")

                for n in cell.neighbours:
                    # print("-----",n.life, n.coords)
                    if n.life == 0:
                        dead += 1

                    if n.life == 1:
                        alive += 1

                #reproduction logic
                if cell.life == 1 and alive < 2:
                    cell.next = 0
                elif cell.life == 1 and (alive == 2 or alive == 3):
                    print("found")
                elif cell.life == 1 and alive > 3:
                    cell.next = 0
                elif cell.life == 0 and alive == 3:
                    print("zero to")
                    cell.next = 1
        print(self)
                 
            
    
    def __str__(self):
            main_str = ""
            for row in self.grid:
                sub_str = ""
                for cell in row:
                    if cell.life == None:
                        sub_str += ' . ' 
                    else:
                        sub_str += f" {cell.life} "
                    # print(cell.life)
                main_str += (sub_str + "\n")
            return main_str

start = [(7,8),(8,8),(8,7),(8,9)]
grid = Grid(15, start)

