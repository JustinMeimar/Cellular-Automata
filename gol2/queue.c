#include "gol.h"

struct sLinkedList* createList(){

	struct sLinkedList* list;
	list = malloc(sizeof(struct sLinkedList*));
	
	return list;
};

struct sLinkedList* add(struct sLinkedList* list, struct node* new){
	
	if(list->size >=8){
		printf("\ntoo big\n");
		return list;
	}
	if(list->size == 0){

		new->next = NULL;

		list->head = new;
		list->size++;

		return list;	
	}
	
	struct node* temp = list->head;

	while(temp->next != NULL){

		temp = temp->next;	
	}

	temp->next = new;
	new->next = NULL;
	list->size++;
	
	return list;
};








