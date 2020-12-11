#ifndef DECOMPRESS_H_INCLUDED
#define DECOMPRESS_H_INCLUDED
#include "../Structure/Structure.h"
Node* create_huff (FILE *dico);
FILE* decompress(FILE* fichier, Node* tree);

#endif // DECOMPRESS_H_INCLUDED
