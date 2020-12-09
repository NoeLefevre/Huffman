#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include "../Structure/Structure.h"
#include "../Pile/Pile.h"
List_node *create_el_node(Node *n);
int list_size(Element *l);
int list_position(Stack *l, Node* p);
void dictionnaire(FILE *fichier,Node *tree,Element *l_occurence);

#endif // DICTIONNAIRE_H_INCLUDED
