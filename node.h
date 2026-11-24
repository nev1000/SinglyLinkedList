#ifndef NODE_H
#define NODE_H

typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
} node;  

void push_front(node** head, int data);
void push_end(node** head, int data);
void print_front_to_back(node** head);

#endif