#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compress.h"
FILE *compress(FILE *fichier, Node **huff_t,Element **tab)
{
    FILE *fichier2=NULL;
    Node *tree=NULL;
    Node_d *a=NULL;
    *tab = occurence_trie(fichier);
    tri_a_bulle(tab);
    *huff_t = arbre_huffman(*tab);
    tree = trees_copy_tree(*huff_t);
    a = dictionnaire_vrai(tree,*tab);
    //print_test(a);
    fseek(fichier,0, SEEK_SET);
    fichier2 = encodage(fichier,a);
    return fichier2;
}
