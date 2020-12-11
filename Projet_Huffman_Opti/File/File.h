#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "../Structure/Structure.h"
typedef struct Queue{
    Node * no;
    struct Queue *next;
}Queue;

void enqueue(Queue** q, Node* val);
Node * dequeue(Queue** q);

#endif // FILE_H_INCLUDED
