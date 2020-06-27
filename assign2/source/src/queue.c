#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if(q->size == MAX_QUEUE_SIZE) 
		return;
	q->proc[q->size] = proc;
	q->size++;	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose priority is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(empty(q))
		return NULL;
	int max_priority = 0;
	int max_position = 0;
	//Find the pcb whose priority is the highest
	for(int i = 0; i < q->size; i++) {
		if(q->proc[i]->priority >= max_priority){
			max_priority = q->proc[i]->priority;
			max_position = i;
		}
	}
	struct pcb_t * remove =  q->proc[max_position];
	for(int i = max_position; i < q->size - 1; i++) {
		q->proc[i] = q->proc[i+1];
	}	
	q->size--;
	return remove;
}

