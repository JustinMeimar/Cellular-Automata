# grid = [[0,0,0],[0,0,0],[0,0,0]]

# holder = [0 for x in range(0,10)]

# auto_grid = [holder for x in range(100)]

# print(auto_grid)
'''
Rules
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each 
of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). 
Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or 
diagonally adjacent. At each step in time, the following transitions occur:

Any live cell with fewer than two live neighbours dies, as if by underpopulation.
Any live cell with two or three live neighbours lives on to the next generation.
Any live cell with more than three live neighbours dies, as if by overpopulation.
Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
These rules, which compare the behavior of the automaton to real life, can be condensed into the following:

Any live cell with two or three live neighbours survives.
Any dead cell with three live neighbours becomes a live cell.
All other live cells die in the next generation. Similarly, all other dead cells stay dead.
The initial pattern constitutes the seed of the system. The first generation is created by applying the above
 rules simultaneously to every cell in the seed, live or dead; births and deaths occur simultaneously, and the 
 discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of 
 the preceding one. The rules continue to be applied repeatedly to create further generations.
'''
import random
import numpy as np

class Cell:

    def __init__(self, life):
  
        self.life = life # 0 = dead, 1 = alive
        self.neighbours = []

    def printNeighbours(self):
        print("-"*40)
        for n in self.neighbours:
            print('neighbours:',n.life)

    

class Grid:
    def __init__(self, sq_len):
        self.sq_len = sq_len
        holder = [Cell(0) for x in range(sq_len)]
        self.grid = np.array(
            [
                holder for x in range(sq_len)
            ]
        )
        self.init_pop()
        # self.show()

    def iter_gen(self):
        pass

    def init_pop(self):
      
        strt_pos = [(15,15),(15,14),(14,15),(15,16)]
        for tup in strt_pos:
            self.grid[tup[0]][tup[1]] = Cell(1)
            current = self.grid[tup[0]][tup[1]]
        # find neighbours
         
            test_n = []
            for i in range(-1,2):
                for j in range(-1,2):
                    if i == 0 and j == 0:
                        # print('self')
                        pass
                    else:
                        # print("CURRENT:", tup, tup[0]+i, tup[1]+j,self.grid[tup[0]+i][tup[1]+j].life)
                        test_n.append(self.grid[tup[0]+i][tup[1]+j])
            
            current.neighbours = test_n
            current.printNeighbours()

    def __str__(self):
        main_str = ""
        for row in self.grid:
            sub_str = ""
            for cell in row:
                sub_str += f"{cell.life}  "
                # print(cell.life)
            main_str += (sub_str + "\n")
        return main_str

grid = Grid(30)
print(grid)