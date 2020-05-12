//add node to linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Work {
    int hour;
    struct Work* next;
} Work;

int main() {
    //declare head
    Work* head = malloc(sizeof(Work));
    int count = 5;
    int hour = 0;
    printf("input hour(%d input): ", count);
    scanf("%d", &hour);
    head->hour = hour;
    head->next = NULL;

    //declare current
    Work* current = head;
    while(--count) { 
        current->next = malloc(sizeof(Work));
        current = current->next;
        scanf("%d", &hour);
        current->hour = hour;
        current->next = NULL;
    }

    //print linked list
    printf("Work hours: ");
    current = head;
    while(current != NULL) {
        printf("[%d] ", current->hour);
        current = current->next;
    }
    printf("\n");

    //choose add number. declare newnode, temp
    Work* newnode = malloc(sizeof(Work));
    Work* temp = malloc(sizeof(Work));
    int add = 0, position = 0;
    while (1) {
        printf("add number and position(1~6): ");
        scanf("%d %d", &add, &position);
        if (position < 1 || position > 6) {
            printf("!!!error!!!\n");
            continue;
        } else {
            break;
        }
    }
    newnode->hour = add;

    //add choose number
    temp = head;
    if (position == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        position -= 2;
        while(--position >= 0) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    free(temp);

    //print linked list
    current = head;
    printf("Work hours: ");
    while(current != NULL) {
        printf("[%d] ", current->hour);
        current = current->next;
    }
    printf("\n");
    return 0;
}
