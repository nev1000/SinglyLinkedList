#include "node.h"
#include "stdlib.h"
#include "stdio.h"

void push_front(node** head, int data){
    node* nodey = malloc(sizeof(node));
    nodey->next = NULL;
    nodey->prev = NULL;
    nodey->value = data;
    if (*head == NULL){
        *head = nodey;
    } else {
        nodey->next = *head;
        (*head)->prev = nodey;
        *head = nodey;
    }
}

void push_end(node** head, int data){
    node* nodey = malloc(sizeof(node));
    nodey->next = NULL;
    nodey->prev = NULL;
    nodey->value = data;
    if (*head == NULL){
        *head = nodey;
    } else {
        node* pointer = *head;
        while (pointer->next != NULL){
            pointer = pointer->next;
        }
        pointer->next = nodey;
        nodey->prev = pointer;
    }
}

void print_front_to_back(node** head){
    node* pointer = *head;
    node* last = *head;
    while (pointer != NULL){
        printf("%d", pointer->value);
        last = pointer;
        pointer = pointer->next;
    }
    pointer = last;
    while (pointer != NULL){
        printf("%d", pointer->value);
        pointer = pointer->prev;
    }
}