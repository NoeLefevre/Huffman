#ifndef ARBRE_HUFFMAN_H_INCLUDED
#define ARBRE_HUFFMAN_H_INCLUDED
#include "../Stucture/Structure.h"
#include "../File/File.h"
Node* trees_copy_tree(Node* tree);
Node* create_node(int val,char charactere);
Queue *create_queue_node(Element *l);
Node * arbre_huffman(Element *l);
#endif // ARBRE_HUFFMAN_H_INCLUDED
