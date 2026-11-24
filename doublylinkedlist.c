    #include <stdlib.h>
    #include <stdio.h>
    #include "node.h"

    int main(void){
        node* head = malloc(sizeof(node));
        head->next = NULL;
        head->prev = NULL;
        node** headpointer = &head;
        for (int i = 0 ; i < 5 ; i++){
            push_front(headpointer, i);        
        }
        for (int i = 5 ; i < 10 ; i++){
            push_end(headpointer, i);        
        }
        print_front_to_back(headpointer);
    }