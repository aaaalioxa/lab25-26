
#ifndef LAB26_DEQUE_H

typedef struct {
    struct DeqElem *prev;
    struct DeqElem *next;
    int value;
    int index;
} DeqElem;

typedef struct {
    DeqElem *head;
    DeqElem *tail;
    int size;
} DeqStruct;

int RInput(char *str, int op);
int GiveIndex(DeqStruct* deq);
int PushFrontDeq(DeqStruct* deq, int value);
int PopBackDeq(DeqStruct* deq);
int PushBackDeq(DeqStruct* deq, int value);
int PopFrontDeq(DeqStruct* deq);
int PrintDeq(DeqStruct* deq);
DeqStruct* CreateDeq();
void DestroyDequeue(DeqStruct* deq);
void Swap(DeqElem* a, DeqElem* b);
DeqElem* GetElement(DeqStruct* deq, int i);
int SelectionSort(DeqStruct* deq);

#define LAB26_DEQUE_H

#endif //LAB26_DEQUE_H
