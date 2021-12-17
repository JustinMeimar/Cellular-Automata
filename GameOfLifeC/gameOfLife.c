//"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"
#include <stdio.h>
#include <stdlib.h>
#include "neighborStruct.c"

#define WIDTH 10

#define LENGTH 10


struct cell{
	int x;
	int y;
	int state;
	Queue *neighbors;
//	neighbors = calloc(sizeof(struct cell*)* 8);
};

struct grid{

	int width, length;
	struct cell *cells[WIDTH][LENGTH];

};
void neighbors(struct cell* cur, struct grid* g){	
	
	int x = cur->x;
	int y = cur->y;

	int tx = 0;
	int ty = 0;

	cur->state = 1;
	for(int i =-1; i< 2; i++){
			
		ty=0;
		for(int j = -1; j< 2; j++){
			
			//edge cases

			if(i == 0 && j == 0){
				ty++;
				continue;
			}
			if(x + i < 0 || x + i >= WIDTH){
				ty++;	
				continue;		
			}
			else if(y +j < 0 || y + j >= LENGTH){
				ty++;	
				continue;		
			}
			else{
				printf("%d, %d.... %d %d.... %d %d\n", i , j, i+x, j+y, ty, tx);
				Enqueue(cur->neighbors, 3);
			}
			ty++;
		}
		tx++;
	}
	printf("((%d))", cur->neighbors->size);
	/*
	for(int n=0;n<8;n++){
		if(*(cur->neighbors[n]) == 1230){
			printf("%d\n", cur->neighbors[n]->x);
		}
	}
	*/
	
	printf("\n");

}

void printGrid(struct grid* g){
	printf("game state");	
	
	for(int i = 0; i< WIDTH; i++){
		printf("\n");
		for(int j = 0; j< LENGTH; j++){
			printf("%d ", g->cells[i][j]->state);
		}
	}
}

int main(){
	
	struct grid* myGrid;	
	myGrid = (struct grid*)malloc(sizeof(struct grid));

	for(int i = 0; i< WIDTH; i++){
		for(int j=0; j< LENGTH; j++){
			struct cell* c = (struct cell*)malloc(sizeof(struct cell));
			
			c->x = j; 
			c->y = i;
			c->state = 0;
			c->neighbors = createQueue(8);

			myGrid->cells[i][j] = c;	
			
		}
	}
	neighbors(myGrid->cells[0][3], myGrid);		
	printGrid(myGrid);
	return 0;
}

