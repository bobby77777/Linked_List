//main.c

#include <stdio.h>
#include <stdlib.h>
#include "global.h"

// void Assign_Linkedlist(Data*, int*, int);
// Data* Add_First(Data*);
// Data* Replace_First(Data*);
// void Print_Linkedlist(Data*);
// void Add_or_Replace(Data*);

int main() {
    //declare *head and *current
    Data* head = malloc(sizeof(Data));
    Data* current = head;
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(*data);
    Assign_Linkedlist(head, data, size);
    //origin
    printf("origin  ->  ");
    Print_Linkedlist(head);
    Add_or_Replace(head);
    return 0;
}