//delete node from linked list

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
        printf("%d ", current->hour);
        current = current->next;
    }
    printf("\n");

    //choose delete number. declare temp, following
    Work* temp = malloc(sizeof(Work));
    Work* following = malloc(sizeof(Work));
    printf("delete number: ");
    int delete = 0;
    scanf("%d", &delete);

    //delete choose number
    temp = head;
    if (head->hour == delete) {
        head = head->next;
    } else { 
        while((temp != NULL) && (temp->hour != delete)) {
            following = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Not found\n");
        } else {
            following->next = temp->next;
        }
    }
    free(temp);

    //print linked list
    current = head;
    printf("Work hours: ");
    while(current != NULL) {
        printf("%d ", current->hour);
        current = current->next;
    }
    printf("\n");







    // while(1) {
    //     printf("work hours\n");
    //     current = head;
    //     printf("%d\n", current->hour);
    //     current = current->next;
    //     if (current == NULL) break;
    // }
    



    // Work bob, julia, mac;
    // Work* head;
    // head = &bob;

    // // printf("%p\n%p\n", head, &bob);
    
    // bob.hour = 5;
    // bob.next = &julia;

    // julia.hour = 8;
    // julia.next = &mac;

    // mac.hour = 3;
    // mac.next = NULL;

    // while(head != NULL) {
    //     printf("|| %14p || %14d || %14p ||\n", head, head->hour, head->next);
    //     head = head->next;
    // }
    return 0;
}
