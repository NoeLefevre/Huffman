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


typedef struct List_node{
    Node *no;
    struct Stack *next;
}List_node;

typedef struct Node_d {
    char charactere;
    char *code;
    struct Node* left;
    struct Node* right;
} Node_d;

#endif // STRUCTURE_H_INCLUDED
