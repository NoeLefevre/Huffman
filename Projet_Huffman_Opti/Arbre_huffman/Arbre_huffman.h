#ifndef ARBRE_HUFFMAN_H_INCLUDED
#define ARBRE_HUFFMAN_H_INCLUDED
#include "../Structure/Structure.h"
#include "../File/File.h"
Node* create_node(int val,char charactere);
Queue *create_queue_node(Element *l);
Node * arbre_huffman(Element *l);
#endif // ARBRE_HUFFMAN_H_INCLUDED
