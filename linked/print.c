//print.c

#include <stdio.h>
#include <stdlib.h>
#include "print.h"

void Print_Linkedlist(Data* head) {
    Data* current = head;
    while(current->next != NULL) {
        printf("[%2d] ", current->age);
        current = current->next;
    }
    printf("\n");
}