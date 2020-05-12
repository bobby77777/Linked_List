//delete node from linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int age;
    struct Data* next;
} Data;

int main() {
    //declare *head
    int size = 6;
    int data[] = {1, 2, 3, 4, 5, 6};
    int temp_size = size;
    int age;
    Data* head = malloc(sizeof(Data));

    //declare *current
    Data* current = head;
    // printf("input %d age: ", size);
    while(temp_size--) {
        // scanf("%d", &age);
        // current->age = age;
        current->age = data[(size-1) - temp_size];
        current->next = malloc(sizeof(Data));
        current = current->next;
        current->next = NULL;
    }

    //print linked list
    current = head;
    while(current->next != NULL) {
        printf("[%d] ", current->age);
        current = current->next;
    }
    printf("\n");

    //delete node
    current = head;
    Data* temp = malloc(sizeof(Data));
    Data* following = malloc(sizeof(Data));
    // int position;
    // printf("input age and position to delete(1 ~ %d): ", size);
    // scanf("%d %d", &age, &position);
    printf("input age: ");
    scanf("%d", &age);
    if (head->age == age) {
        temp = head;
        head = head->next;
    } else {
        while((current != NULL) && (current->age != age)) {
            following = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("not in linked list\n");
        } else {
            following->next = current->next;
        }
    }
    free(temp);
    free(following);

    //print new linked list
    current = head;
    while(current->next != NULL) {
        printf("[%d] ", current->age);
        current = current->next;
    }
    printf("\n");


    return 0;
}