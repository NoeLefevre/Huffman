#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct Element {
    char charactere;
    int data;
    struct Element *next;
} Element;

typedef struct Node {
    char charactere;
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct List_node
{
    Node * no;
    struct List_node *next;
}List_node;

#endif // STRUCTURE_H_INCLUDED
