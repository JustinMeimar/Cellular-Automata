#include "gol.h"

int main(){
	
	struct grid* g = createGrid();	
	
	//struct Queue *n = neighbors(g->cells[0][3], g);		struct cell* test = g->cells[0][3];
	g->cells[0][2]->state = 1;	
	g->cells[1][2]->state = 1;

	for(int i = 0; i<3000; i++){
		printGrid(g);
		updateGridState(g);
	}		
	
	//printf("\n%d\n", test->neighbors);
	/*struct sLinkedList* list = create(0);
	printf("%d", list->size);
	struct cell* c;	
	c = malloc(sizeof(struct cell*));
	struct node* n;	
	n = malloc(sizeof(struct node*));
	
	n->cur = c;
	n->next = NULL;

	add(list, n);

	printf("%d", list->size);
	*/	
	return 0;		

}
