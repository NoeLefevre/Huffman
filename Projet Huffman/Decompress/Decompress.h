#ifndef DECOMPRESS_H_INCLUDED
#define DECOMPRESS_H_INCLUDED
#include "../Stucture/Structure.h"
#include "../Arbre_huffman/Arbre_huffman.h"
Node* create_huff (FILE *dico);
FILE *decompress(FILE* fichier,Node *tree);

#endif // DECOMPRESS_H_INCLUDED
