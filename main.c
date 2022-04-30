#include <stdio.h>
#include <stdbool.h>
#include "deque.h"

int main() {
    DeqStruct* deq = CreateDeq();
    int n;
    int op;
    char op1[] = "";
    char n1[] = "";
    printf("------------------------------------------------\n");
    printf("0 - add new element to the front\n");
    printf("1 - add new element to the back\n");
    printf("2 - delete the first element\n");
    printf("3 - delete the last element\n");
    printf("4 - print the dequeue\n");
    printf("5 - sort the dequeue and delete the maximum\n");
    printf("6 - destroy the dequeue\n");
    printf("7 - end the program\n");
    printf("------------------------------------------------\n");
    while (true) {
        printf("Enter option: ");
        do {
            scanf("%s", op1);
            op = RInput(op1, 0);
        } while (op == -1);
        if (op == 0) {
            printf("Enter value: ");
            do {
                scanf("%s", n1);
                n = RInput(n1, 1);
            } while (n == -1);
            PushFrontDeq(deq, n);
        }
        else if (op == 1) {
            printf("Enter value: ");
            do {
                scanf("%s", n1);
                n = RInput(n1, 1);
            } while (n == -1);
            PushBackDeq(deq, n);
        }
        else if (op == 2){
            if (deq->head != NULL) {
                printf("Deleting first element\n");
                PopFrontDeq(deq);
            }
            else
                printf("The dequeue is empty");
        }
        else if (op == 3){
            if (deq->head != NULL) {
                printf("Deleting last element\n");
                PopBackDeq(deq);
            }
            else
                printf("The dequeue is empty\n");
        }
        else if (op == 4) {
            PrintDeq(deq);
        }
        else if (op == 5) {
            if (deq->head != NULL) {
                SelectionSort(deq);
                PopBackDeq(deq);
                printf("Sorted!\n");
            }
            else
                printf("Nothing to sort\n");
        }
        else if (op == 6) {
            DestroyDequeue(deq);
        }
        else if (op == 7) {
            break;
        }
        else
            printf("There is no such option, try again!\n");
    }
    return 0;
}
