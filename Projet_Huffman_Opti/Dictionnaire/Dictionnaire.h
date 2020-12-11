#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include "../Structure/Structure.h"
#include "../Pile/Pile.h"
List_node *create_el_node(Node *n);
int list_position(Stack *l, Node* p);
Node_d* create_node2(char c,char* code);
int depth(Node_d* tree);
void add_node_BST(Node_d** tree, Node_d* node);
int bf(Node_d* tree);
void right_rotation(Node_d** tree);
void left_rotation(Node_d** tree);
void balance(Node_d** tree);
void add_node_AVL(Node_d** tree, Node_d* node);
Node_d *dictionnaire_vrai(FILE **fichier,Node **tree,Element *l_occurence);
#endif // DICTIONNAIRE_H_INCLUDED
