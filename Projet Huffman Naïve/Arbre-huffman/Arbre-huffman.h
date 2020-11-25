#ifndef ARBRE-HUFFMAN_H_INCLUDED
#define ARBRE-HUFFMAN_H_INCLUDED
#include "../Structure/Structure.h"
Node * arbre_huffman(Element *l);
List_node *create_list_node(Element *l);
Node* trees_copy_tree(Node* tree);
void list_remove(List_node** l, List_node* el);
void ajouter_ln_fin(List_node** liste, List_node* el);
Node* create_node(int val,char charactere);

#endif // ARBRE-HUFFMAN_H_INCLUDED
