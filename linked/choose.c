//choose.c

#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "add.h"
#include "replace.h"
#include "choose.h"

void Add_or_Replace(Data* head) {
    int choose = 0;
    printf("choose add(1) or replace(2): ");
    scanf("%d", &choose);
    switch(choose) {
        case 1:
            //Add
            head = Add_First(head);
            printf("Add     ->  ");
            Print_Linkedlist(head);
            break;
        case 2:
            //Replace
            head = Replace_First(head);
            printf("Replace ->  ");
            Print_Linkedlist(head);
            break;
        default:
            printf("!!!error!!!\n");
            Add_or_Replace(head);
    }
}