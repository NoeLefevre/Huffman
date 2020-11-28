#ifndef COMPRESS_H_INCLUDED
#define COMPRESS_H_INCLUDED
#include "../Arbre_huffman/Arbre_huffman.h"
#include "../Dictionnaire/Dictionnaire.h"
#include "../Encodage/Encodage.h"
#include "../Liste_occurence/Liste_occurence.h"
#include "../Stucture/Structure.h"
FILE *compress(FILE *fichier, Node **huff_t,Element **tab);

#endif // COMPRESS_H_INCLUDED
