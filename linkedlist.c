#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int age;
    struct Data* next;
} Data;

void Assign_Linkedlist(Data*);
void Print_Linkedlist(Data*);
Data* Add(Data*);
Data* Delete(Data*);
Data* Reverse(Data*);
Data* Clear(Data*);

void Assign_Linkedlist(Data* head) {
    int age = 0;
    int size = 5;
    printf("input %d data: ", size);
    scanf("%d", &age);
    head->age = age;
    head->next = NULL;

    Data* current = head;
    for (int i = 0 ; i < size-1 ; i++) {
        current->next = malloc(sizeof(Data));
        current = current->next;
        scanf("%d", &age);
        current->age = age;
        current->next = NULL;
    }
}

void Print_Linkedlist(Data* head) {
    if (head == NULL) {
        printf("NULL");
    }
    Data* current = head;
    while(current != NULL) {
        printf("[%2d] ", current->age);
        current = current->next;
    }
}

Data* Add(Data* head) {
    Data* current = head;
    Data* newnode = malloc(sizeof(Data));
    Data* temp = malloc(sizeof(Data));
    int age, position;
    scanf("%d %d", &age, &position);
    newnode->age = age;
    switch(position) {
        case 1:
            newnode->next = head;
            head = newnode;
            break;
        default:
            while(--position) {
                temp = current;
                current = current->next;
            }
            temp->next = newnode;
            newnode->next = current;
    }
    return head;
}

Data* Delete(Data* head) {
    Data* current = head;
    Data* temp = malloc(sizeof(Data));
    int delete = 0;
    scanf("%d", &delete);
    if (current->age == delete) {
        head = head->next;
    } else {
        while((current != NULL) && (current->age != delete)) {
            temp = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("not in list ");
        } else {
            temp->next = current->next;
        }
    }
    free(current);
    free(temp);
    return head;
}

//previous->current->following => following->current->previous
Data* Reverse(Data* head) {
    Data *previous = NULL,
         *current = head,
         *following = current->next;
    while(following != NULL) {
        current->next = previous;
        previous = current;
        current = following;
        following = following->next;
    }
    current->next = previous;
    head = current;
    return head;
}

Data* Clear(Data* head) {
    while (head != NULL) {
        Data* current = head;
        head = head->next;
        free(current);
    }
    return head;
}

int main() {
    Data* head = malloc(sizeof(Data));
    Assign_Linkedlist(head);
    Print_Linkedlist(head);
    printf("-> ");
    int choose = 0;
    ERROR:
    scanf("%d", &choose);
    switch(choose) {
        case 1:
            head = Reverse(head);
            break;
        case 2:
            head = Delete(head);
            break;
        case 3:
            head = Add(head);
            break;
        case 4:
            head = Clear(head);
            break;
        default:
            printf("!!error!!");
            goto ERROR;

    }
    Print_Linkedlist(head);
    printf("\n");
    return 0;
}