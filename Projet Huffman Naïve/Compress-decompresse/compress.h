#ifndef COMPRESS_H_INCLUDED
#define COMPRESS_H_INCLUDED
#include "../Binaire/Binaire.h"
#include "../Dictionnaire/Dictionnaire.h"
#include "../Arbre-huffman/Arbre-huffman.h"
#include "../Liste_occurence/Liste_occurence.h"
#include "Encodage.h"
#include "Decompress.h"
#include "../Structure/Structure.h"


FILE *compress(FILE* fichier);
FILE *compress2(FILE* fichier);
#endif // COMPRESS_H_INCLUDED
