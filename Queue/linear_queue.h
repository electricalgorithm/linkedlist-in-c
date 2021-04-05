/*
 * linear_queue.h
 *
 *  Created on: 6 Apr 2021
 *      Author: electricalgorithm
 */

#ifndef LINEAR_QUEUE_H_
#define LINEAR_QUEUE_H_

#ifndef NULL
	#define NULL   ((void *) 0)
#endif

/*		Types		*/
typedef struct lqnode {
	long int num;
	struct lqnode* next = NULL;
	struct lqnode* prev = NULL;
	// It is not mandatory to be a integer.
} LQ_node_t;
typedef struct lqueue {
	LQ_node_t* head_node = NULL;
	LQ_node_t* tail_node = NULL;
} L_Queue_t;


/*		Functions		*/
void lq_push(L_Queue_t*, LQ_node_t*);
LQ_node_t lq_pop(L_Queue_t*);
LQ_node_t lq_concat(L_Queue_t*, L_Queue_t*);
void lq_travel_print(L_Queue_t*);

#endif /* LINEAR_QUEUE_H_ */
