#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int value;
    struct node* next;
} node;

void print_list(node* head);
void push_front(node** nodey, int value);
void free_list();

int main(void){
    node* head = NULL;
    node** nodey = &head;
    push_front(nodey, 2);
    push_front(nodey, 4);
    push_front(nodey, 5);
    push_front(nodey, 6);
    print_list(head);
}

void push_front(node** nodey, int value){
    node* boom = malloc(sizeof(node));
    boom->value = value;
    if (*nodey == NULL){
        boom->next = NULL;
    } else {
        boom->next = *nodey;   
    }
    *nodey = boom;
}

void free_list(node* head){
    
}

void print_list(node* head){
    node* pointer = head;
    while (pointer != NULL){
        printf("%d", pointer->value);
        pointer = pointer->next;
    }
}
