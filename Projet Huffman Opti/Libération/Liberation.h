#ifndef LIBERATION_H_INCLUDED
#define LIBERATION_H_INCLUDED
#include "../Structure/Structure.h"
#include "../File/File.h"
#include "../Pile/Pile.h"
void free_tab(Element* tab);
void free_node(Node* tree);
void free_node2(Node_d* tree);
void free_queue(Queue *q);
void free_stack(Stack *p);
#endif // LIBERATION_H_INCLUDED
