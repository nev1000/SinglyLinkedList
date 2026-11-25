#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int value;
    struct node* next;
} node;

node* create_node();
node* push_end(node* nodey, node* head);
void print_list(node* head);
void free_list(node* head);

int main (void){
    srand((unsigned)time(NULL));
    node* head = create_node();
    node* first = create_node();
    node* second = create_node();
    node* third = create_node();
    push_end(first, head);
    push_end(second, head);
    push_end(third, head);
    print_list(head);
    free_list(head);
    printf("Freed!");
    print_list(head);
}

node* create_node(){
    print("test");
    int n = rand() % 20;
    node* nodey = malloc(sizeof(node));
    nodey->value = n;
    nodey->next = NULL;
    return nodey;
}

node* push_end(node* nodey, node* head){
    node* pointer = head;
    while (pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = nodey;
    return head;
}

node* push_end(node** head, node* nodey){
    if (*head == NULL){
        *head = nodey;
        return;
    } node* pointer = *head;
    while (pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = nodey;
}

void free_list(node* head){
    node* pointer = head;
    while(pointer != NULL){
        node* old = pointer;
        pointer = pointer->next;
        free(old);
    }
}

void print_list(node* head){
    node* pointer = head;
    while (pointer != NULL){
        printf("FOUND A NODE!: %d\n", pointer->value);
        pointer = pointer->next;
    }
}