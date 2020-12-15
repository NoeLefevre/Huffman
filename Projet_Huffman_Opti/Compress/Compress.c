#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compress.h"
#include "../Arbre_huffman/Arbre_huffman.h"
#include "../Dictionnaire/Dictionnaire.h"
#include "../Encodage/Encodage.h"
#include "../Liste_occurence/Liste_occurence.h"
#include "../Libération/Liberation.h"
FILE *compress(FILE **dictio,FILE *text, Node **huff_t,Element **tab)
{
    FILE *Encodage=NULL;
    Node *tree=NULL;
    Node_d* a = NULL;
    *tab = occurence_trie(text);
    tri_a_bulle(tab);
    *huff_t = arbre_huffman(*tab);
    a = dictionnaire_vrai(dictio,huff_t,*tab);
    fseek(text,0, SEEK_SET);
    Encodage = encodage(text,a);
    free_node2(a);
    free_node(tree);
    return Encodage;
}
