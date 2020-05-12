//add node to linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int age;
    struct Data* next;
} Data;

int main() {
    //declare *head
    int size = 5; //linked list size
    int temp_size = size;
    int age = 0;  //input age
    Data* head = malloc(sizeof(Data));


    //declare *current
    Data* current = head;
    printf("input %d data(age): ", size);
    while(temp_size--) {
        scanf("%d", &age);
        current->age = age;
        current->next = malloc(sizeof(Data));
        current = current->next;
        current->next = NULL;
    }
    printf("\n");


    //print new linked list
    current = head;
    while(current->next != NULL) {
        printf("[%d] ", current->age);
        current = current->next;
    }
    printf("\n");

    //add node
    current = head;
    Data* newnode = malloc(sizeof(Data));
    int add, position;
    while(1) {
        printf("input age and position(1 ~ %d) to add: ", size + 1);
        scanf("%d %d", &add, &position);
        if (position < 1 || position > 6) {
            printf("!!!error!!!\n");
            continue;
        } else {
            break;
        }
    }
    newnode->age = add;
    if (position == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        position-=1;
        while(--position) {
            current = current->next;    
        }
        newnode->next = current->next;
        current->next = newnode;
    }


    //print new linked list
    current = head;
    while(current->next != NULL) {
        printf("[%d] ", current->age);
        current = current->next;
    }
    printf("\n");
    return 0;
}