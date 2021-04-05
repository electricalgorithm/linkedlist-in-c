/*
 * linear.c
 *
 *  Created on: 6 Apr 2021
 *      Author: electricalgorithm
 */

#include "linear_queue.h"
#include <stdlib.h>
#include <stdio.h>

int main (void) {
	/* THIS MAIN FUNCTION FOR TEST
	 * PURPOSES ONLY. I AM AWARE OF
	 * THAT ARRAY IS CONTINUES DATA
	 * TYPE IN THE RAM. 				*/

	L_Queue_t* queue_one = (L_Queue_t*) malloc(sizeof(L_Queue_t));
	L_Queue_t* queue_two = (L_Queue_t*) malloc(sizeof(L_Queue_t));

	/*		Node Creation for 1st		*/
	LQ_node_t* nodes_a = (LQ_node_t*) malloc(10 * sizeof(LQ_node_t));

	for (int index = 0; index < 10; index++) {
		nodes_a[index].num = random();
		lq_push(queue_one, nodes_a);
	}

	/*		Node Creation for 2nd		*/
	LQ_node_t* nodes_b = (LQ_node_t*) malloc(20 * sizeof(LQ_node_t));

	for (int index = 0; index < 20; index++) {
		nodes_b[index].num = random();
		lq_push(queue_two, nodes_b);
	}

	/*		Concating two queues		*/
	lq_concat(queue_one, queue_two);
	/*		Printing					*/
	lq_travel_print(queue_one);

	/*		Poping elements				*/
	int pop_count = 7;
	for (int index = 0; index < pop_count+1; index++) {
		printf("popped: %ld", lq_pop(queue_one).num);
	}

	/*		Printing					*/
	lq_travel_print(queue_one);

}
