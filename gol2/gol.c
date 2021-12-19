#include "gol.h"

/*
void updateState(struct grid* g){
	//itterate through items in grid, collect neighbors, make decision based off
	for(){
		for(){

		}
	}
}
*/


int neighbors(struct cell* cur, struct grid* g){	
	
	int x = cur->x;
	int y = cur->y;
	int count = 0;

	for(int i =-1; i< 2; i++){
		for(int j = -1; j< 2; j++){	
			//edge cases
			if(i == 0 && j == 0){
				continue;
			}
			if(x + i < 0 || x + i >= WIDTH){
				continue;		
			}
			else if(y +j < 0 || y + j >= LENGTH){
				continue;		
			}
			else{
				printf("%d, %d.... %d %d\n", i , j, i+x, j+y);
				//struct cell* test = (struct cell*)malloc(sizeof(struct cell
				if(g->cells[j+y][i+x]->state == 1){
					cur->neighbors++;
				}				
			}
		}
	}
	//printf("((%d))", cur->neighbors->size);
	return 1;
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

struct grid* createGrid(){
	
	struct grid* myGrid;		

	myGrid = (struct grid*)malloc(sizeof(struct grid));

	for(int i = 0; i< WIDTH; i++){
		for(int j=0; j< LENGTH; j++){ 
			struct cell* c = (struct cell*)malloc(sizeof(struct cell*));
			
			c->x = j; 
			c->y = i;
			c->state = 0;
			c->neighbors = 0;
			
			myGrid->cells[i][j] = c;				
		}
	}
	return myGrid;
}

