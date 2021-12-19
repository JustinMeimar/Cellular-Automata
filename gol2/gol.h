#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define LENGTH 10

struct cell{
	int x;
	int y;
	int state;
	int neighbors;
	//struct sLinkedList* neighbors;
//	neighbors = calloc(sizeof(struct cell*)* 8);
};

struct grid{ 
	int width, length;
	struct cell *cells[WIDTH][LENGTH];

};

struct node{	
	struct cell* cur;
	struct node* next;
};

struct sLinkedList{
	
	struct node* head;

	int size;
};
/*
struct Queue{

	int capacity;
	int size;
	int front;
	int rear;
	struct cell* elements;
};
*/

//gol.c
struct grid* createGrid();
void printGrid(struct grid* g);
int neighbors(struct cell* cur, struct grid* g);
void updateState(struct grid* g);
/*
//queue.c
void Enqueue(struct Queue *Q,struct cell* element);
struct Queue* createQueue(int maxElements);

*/


//slinked.c
struct sLinkedList* createList();
struct sLinkedList* add(struct sLinkedList* list, struct node* new);


