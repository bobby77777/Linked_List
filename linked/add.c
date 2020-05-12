//add.c

#include <stdio.h>
#include <stdlib.h>
#include "add.h"

Data* Add_First(Data* head) {
    int add = 0;
    Data* newnode = malloc(sizeof(Data));
    printf("\ninput add number:     ");
    scanf("%d", &add);
    newnode->age = add;
    newnode->next = head;
    head = newnode;
    free(newnode);
    return head;
}