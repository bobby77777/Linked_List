//assign.c

#include <stdio.h>
#include <stdlib.h>
#include "assign.h"

void Assign_Linkedlist(Data* head, int* data, int size) {
    Data* current = head;
    for (int i = 0 ; i < size ; i++) {
        current->age = data[i];
        current->next = malloc(sizeof(Data));
        current = current->next;
        current->next = NULL;
    }
}