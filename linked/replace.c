//replace.c

#include <stdio.h>
#include <stdlib.h>
#include "replace.h"

Data* Replace_First(Data* head) {
    int Replace = 0;
    Data* newnode = malloc(sizeof(Data));
    printf("\ninput Replace number: ");
    scanf("%d", &Replace);
    newnode->age = Replace;
    newnode->next = head->next;
    head = newnode;
    free(newnode);
    return head;
}