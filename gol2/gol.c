#include "gol.h"


void updateCellState(struct cell* cur){
	//printf("(%d)", n);		
	int n = cur->neighbors;

	if(n < 2){
		cur->nextState = 0;
	}
	else if((n == 2 || n == 3) && cur->state == 1){
		cur->nextState = 1;	
	}
	else if(n > 3 && cur->state == 1){
		cur->nextState = 0;	
	}
	else if((cur->state == 0) && n > 3){
		cur->nextState = 1;	
	}
}

void updateGridState(struct grid* g){
	//itterate through items in grid, collect neighbors, make decision based off
	printf("\n");
	for(int x = 0; x< WIDTH; x++){
		//printf("\n");	
		for(int y = 0; y < LENGTH; y++){	
			struct cell* cur = g->cells[x][y];
			neighbors(cur, g);	
			updateCellState(cur);		
		}
	}
	for(int i = 0; i< WIDTH; i++){
		//printf("\n");	
		for(int j = 0; j < LENGTH; j++){	
			struct cell* cur = g->cells[i][j];
			cur->state = cur->nextState;
		}
	}	
}

void neighbors(struct cell* cur, struct grid* g){	
	
	int x = cur->x;
	int y = cur->y;
	int count = 0;
	cur->neighbors = 0;
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
				if(g->cells[j+y][i+x]->state == 1){
					cur->neighbors++;
				}				
			}
		}
	}
	return;
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
	srand(time(NULL));

	myGrid = (struct grid*)malloc(sizeof(struct grid));

	for(int i = 0; i< WIDTH; i++){
		for(int j=0; j< LENGTH; j++){ 
			struct cell* c = (struct cell*)malloc(sizeof(struct cell*));
			int r = rand();	

			c->x = j; 
			c->y = i;
			
			if(r % 2 == 0){
				c->state = 1;	
			}else{
				c->state = 0;
			}
			
			//c->state = 0;			
			c->neighbors = 0;
			
			myGrid->cells[i][j] = c;				
		}
	}
	return myGrid;
}

