/* 
# Linkedlist Implementation 
Insert sorted list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* prevNode;
    struct node* nextNode;
    char* content;
} Node;

typedef struct head {
    struct node* first_element;
    struct node* cursor;
} Head;

void travel_inverse(Head* list) {
    Node* pointer = list->first_element;
    while (1) {
        printf("%s\n", pointer->content);
        if (pointer->nextNode != NULL) pointer = pointer->nextNode;
        else break;
    }
}

void travel_reverse(Head* list) {
    Node* pointer = list->cursor;
    while (1) {
        printf("%s\n", pointer->content);
        if (pointer->prevNode != NULL) pointer = pointer->prevNode;
        else break;
    }
}

Node* create_node(char* content) {
    Node* returned = (Node*) malloc(sizeof(Node));
    returned->prevNode = NULL;
    returned->nextNode = NULL;
    returned->content = content;
    return returned;
}

Head* create_llist(Node* init) {
    Head* llist = (Head*) malloc(sizeof(Head));
    llist->first_element = init;
    llist->cursor = llist->first_element;
    return llist;
}

void append_node_end(Head* list, Node* to_appended) {
    // Updating the Node.
    to_appended->nextNode = NULL;
    to_appended->prevNode = list->cursor;
    // Updating the list.
    list->cursor->nextNode = to_appended;
    list->cursor = to_appended;
}

void append_node_start(Head* list, Node* to_appended) {
    // Updating the Node.
    to_appended->prevNode = NULL;
    to_appended->nextNode = list->first_element;
    // Updating the list.
    list->first_element->prevNode = to_appended;
    list->first_element = to_appended;
}

void replace_after(Head* list, Node* to_appended, Node* previous) {
    // Updating next node
    previous->nextNode->nextNode->prevNode = to_appended;
    // Updating the to_appended
    to_appended->nextNode = previous->nextNode->nextNode;
    to_appended->prevNode = previous;
    // Deleting and updating previous node
    free(previous->nextNode);
    previous->nextNode = to_appended;
}

void replace_before(Head* list, Node* to_appended, Node* next) {
    // Updating the previous node
    next->prevNode->prevNode->nextNode = to_appended;
    // Updating the to_appended
    to_appended->prevNode = next->prevNode->prevNode;
    to_appended->nextNode = next;
    // Deleting and updating next node
    free(next->prevNode);
    next->prevNode = to_appended;
}

void delete_after(Head* list, Node* previous) {
    Node* tmp = previous->nextNode->nextNode;
    previous->nextNode->nextNode->prevNode = previous;
    free(previous->nextNode);
    previous->nextNode = tmp;
}

void delete_before(Head* list, Node* next) {
    Node* tmp = next->prevNode->prevNode;
    next->prevNode->prevNode->nextNode = next;
    free(next->prevNode);
    next->prevNode = tmp;
}

void append_after(Head* list, Node* to_appended, Node* previous) {
    // Updating next node
    previous->nextNode->prevNode = to_appended;
    // Updating the to_appended
    to_appended->nextNode = previous->nextNode;
    to_appended->prevNode = previous;
    // Updating previous node
    previous->nextNode = to_appended;
}

void append_before(Head* list, Node* to_appended, Node* next) {
    // Updating the previous node
    next->prevNode->nextNode = to_appended;
    // Updating the to_appended
    to_appended->prevNode = next->prevNode;
    to_appended->nextNode = next;
    // Updating next node
    next->prevNode = to_appended;
}

void concat(Head* first_list, Head* second_list) {
    first_list->cursor->nextNode = second_list->first_element;
    first_list->cursor = second_list->cursor;
    free(second_list);
}

int main(void) {
    // Creating the LinkedList
    Head* linked_list = create_llist(NULL);
    
    // Creating the first Node.
    Node* node_a = create_node("First!");

    // Initilization of the first Node in the list.
    linked_list->first_element = node_a;
    linked_list->cursor = node_a;

    // Creating the second Node.
    Node* node_b = create_node("Second!");
    append_node_end(linked_list, node_b);

    // Creating the third Node.
    Node* node_c = create_node("Third!");
    append_node_end(linked_list, node_c);

    // Creating the fourth Node.
    Node* node_d = create_node("Last one!");
    append_node_end(linked_list, node_d);

    // Creating the fifth Node at beginning.
    Node* node_e = create_node("Begin!");
    append_node_start(linked_list, node_e);

    // Creating the sixth Node after Second!.
    Node* node_f = create_node("Middle");
    append_after(linked_list, node_f, node_b);

    // Creating the seventh Node before Second!.
    Node* node_g = create_node("Close to last.");
    append_before(linked_list, node_g, node_b);

    // To print all the elements of the list
    travel_inverse(linked_list);
    printf("\n");
    
    // Creating a different list
    Head* ll2 = create_llist(NULL);
    Node* f_n_2 = create_node("2-1");
    ll2->first_element = f_n_2;
    ll2->cursor = f_n_2;
    append_node_end(ll2, create_node("2-2"));
    append_node_end(ll2, create_node("2-3"));
    append_node_end(ll2, create_node("2-4"));
    append_node_end(ll2, create_node("2-5"));
    travel_reverse(ll2);

    // Concating these two lists
    printf("\n");
    concat(linked_list, ll2);
    travel_inverse(linked_list);

    // Deleting 2-2.
    printf("\n");
    delete_after(linked_list, f_n_2);
    delete_before(linked_list, node_f);
    travel_inverse(linked_list);

    return 0;
}