#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include "../Stucture/Structure.h"
#include "../Pïle/Pile.h"
void ajouter_ln_fin(List_node** liste, List_node* el);
List_node *create_el_node(Node *n);
Node *extract(List_node *liste);
void suppr_fin(List_node **l);
int list_position(List_node *l, Node* p);
Node_d* create_node2(char c,char* code);
int depth(Node* tree);
void add_node_BST(Node_d** tree, Node_d* node);
int bf(Node_d* tree);
void right_rotation(Node_d** tree);
void left_rotation(Node_d** tree);
void balance(Node_d** tree);
void add_node_AVL(Node_d** tree, Node_d* node);
void dictionnaire(FILE *fichier,Node *tree,Element *l_occurence);
Node *dictionnaire_vrai(Node *tree,Element *l_occurence);
#endif // DICTIONNAIRE_H_INCLUDED
