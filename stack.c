#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// create an empty stack
void new_stack(stack *s,int data_size){
    
    s->size = 0;
    s->data_size = data_size;
    s->head = NULL; 

}

// push an element to s
void push(stack* s, void* element){

    stack_node *node = malloc(sizeof(stack_node));
    node->data = malloc(s->data_size);
    memcpy(node->data, element, s->data_size);

    node->next = s->head;
    s->head = node;
    s->size++;

}

// pop the last added element in the stack
void* pop(stack* s){

    if(!size(s)){
        printf("Stack is empty !\n");
        exit(1);
    }
    
    stack_node* tmp = s->head;
    s->head = s->head->next;
    s->size--;
    
    void* data = tmp->data;
    free(tmp);
    
    return data;
}

int size(stack* s){
    return s->size;
}


void free_stack(stack* s)
{
    stack_node *tmp;
    while(s->head) {
        tmp = s->head;
        s->head = s->head->next;
        free(tmp->data);
        free(tmp);
    }
}

// prints the stack
void print_stack(stack s, void (*print_data)(void* data)){
    
    stack_node *tmp = s.head;
    while(tmp) {
        print_data(tmp->data);
        tmp = tmp->next;
    }
}