/*
 * linear_queue.c
 *
 *  Created on: 6 Apr 2021
 *      Author: pop49
 */

#include "linear_queue.h"

void
lq_push (L_Queue_t* p_queue,
		 LQ_node_t* p_node	)
{
	if (p_queue->head_node == NULL) p_queue->head_node = p_node;
	else
	{
		p_queue->tail_node->next = p_node;
		p_queue->tail_node = p_node;
	}
}

LQ_node_t
lq_pop	(L_Queue_t* p_queue)
{
	LQ_node_t r_node;
	LQ_node_t* next_node;

	r_node = *(p_queue->head_node);
	next_node = p_queue->head_node->next;
	free(p_queue->head_node);
	p_queue->head_node = next_node;

	return r_node;
}
