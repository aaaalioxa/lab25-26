#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

int RInput(char *str, int op) {
    char *str1 = str;
    bool f = 1;
    while (*str) {
        if (*str < '0' || *str >'9')
            f = 0;
        if (*str == '-')
            f = 1;
        str++;
    }
    if (f)
        return atoi(str1);
    else {
        if (op == 0) {
            printf("Wrong input, try again\n");
            printf("Enter option: ");
        }
        else {
            printf("Wrong input, try again\n");
            printf("Enter value: ");
        }
        return -1;
    }
}

int GiveIndex(DeqStruct* deq) {
    DeqElem* curElement = deq->head;
    int i = 0;
    while (curElement != NULL) {
        curElement->index = i;
        i++;
        curElement = (DeqElem *) curElement->next;
    }
    return 0;
}

int PushFrontDeq(DeqStruct* deq, int value) {
    DeqElem* new = malloc(sizeof(DeqElem));
    new->next = (struct DeqElem *) deq->head;
    new->prev = NULL;
    new->value = value;
    if (deq->tail == NULL) {
        deq->head = deq->tail = new;
    } else {
        deq->head->prev = (struct DeqElem *) new;
        deq->head = new;
    }
    deq->size++;
    GiveIndex(deq);
    return 0;
}

int PushBackDeq(DeqStruct* deq, int value) {
    DeqElem* new = malloc(sizeof(DeqElem));
    new->next = NULL;
    new->prev = (struct DeqElem *) deq->tail;
    new->value = value;
    if (deq->head == NULL) {
        deq->head = deq->tail = new;
    } else {
        deq->tail->next = (struct DeqElem *) new;
        deq->tail = new;
    }
    deq->size++;
    GiveIndex(deq);
    return 0;
}

int PopFrontDeq(DeqStruct* deq) {
    DeqElem *temp = deq->head;
    if (deq->head == deq->tail)
        deq->head = deq->tail = NULL;
    else
        deq->head = (DeqElem *) temp->next;
    deq->size--;
    free(temp);
    GiveIndex(deq);
    return 0;
}

int PopBackDeq(DeqStruct* deq) {
    DeqElem *temp = deq->tail;
    if (deq->head == deq->tail)
        deq->head = deq->tail = NULL;
    else {
        deq->tail = (DeqElem *) temp->prev;
        deq->tail->next = NULL;
    }
    deq->size--;
    free(temp);
    GiveIndex(deq);
    return 0;
}

int PrintDeq(DeqStruct* deq) {
    DeqElem* cur = deq->head;
    if (cur != NULL) {
        while (cur != NULL) {
            if (cur->next != NULL)
                printf("%d -> ", cur->value);
            else
                printf("%d\n", cur->value);
            cur = (DeqElem *) cur->next;
        }
    }
    else
        printf("The dequeue is empty\n");
    return 0;
}

DeqStruct* CreateDeq() {
    DeqStruct *deq = malloc(sizeof(DeqStruct));
    if (deq != NULL) {
        deq->head = deq->tail = NULL;
    }
    deq->size = 0;
    return deq;
}

void DestroyDequeue(DeqStruct* deq) {
    while (deq->head != deq->tail) {
        struct ItemDeque* i = (struct ItemDeque *) deq->head;
        deq->head = (DeqElem *) deq->head->next;
        deq->head->prev = 0;
        free(i);
    }
    deq->head = deq->tail = 0;
}

void Swap(DeqElem* a, DeqElem* b) {
    DeqElem *temp = malloc(sizeof(DeqElem));
    temp->value = a->value;
    a->value = b->value;
    b->value = temp->value;
}

DeqElem* GetElement(DeqStruct* deq, int i) {
    DeqElem* cur = deq->head;
    while (cur != NULL) {
        if (cur->index == i) {
            return cur;
        }
        cur = (DeqElem *) cur->next;
    }
}

int SelectionSort(DeqStruct* deq) {
    for (int step = 0; step < deq->size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < deq->size; i++) {
            if (GetElement(deq, i)->value < GetElement(deq, min_idx)->value)
                min_idx = i;
        }
        Swap(GetElement(deq, min_idx), GetElement(deq, step));
    }
    return 0;
}

