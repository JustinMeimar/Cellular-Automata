#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10

#define LENGTH 10

struct cell{
	int x;
	int y;
	int state;
	struct cell* neighbors[8];
};

void neighbours(struct cell* cur){	
	
	int x = cur->x;
	int y = cur->y;

	for(int i = =-1; i< 2; i++){
		for(int j = -1; j< 2; j++){
			if(x + i < 0 || x + i > WIDTH){
				continue;
			}
			if(y +j < 0 || y + i > LENGTH){
			
			}
		}
	}
}

struct grid{

	int width, length;
	struct cell *cells[WIDTH * LENGTH];

};

int main(){
	
	struct grid* myGrid;	
	myGrid = (struct grid*)malloc(sizeof(struct grid));
	int count = 0;
	for(int i = 0; i< WIDTH; i++){
		printf("\n");
		for(int j=0; j< LENGTH; j++){
			struct cell* c = (struct cell*)malloc(sizeof(struct cell));
			c->x = i; 
			c->y = j;
				
			myGrid->cells[count] = c;
			printf("(%d,%d)", 
					myGrid->cells[count]->x,
					myGrid->cells[count]->y
			);
			
			count++;
		}
	}
	return 0;
}

