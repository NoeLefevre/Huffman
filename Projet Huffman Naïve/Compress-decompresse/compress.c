#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"
#include "../Liberation/Liberation.h"
#include "../Binaire/Binaire.h"
#include "../Dictionnaire/Dictionnaire.h"
#include "../Arbre-huffman/Arbre-huffman.h"
#include "../Liste_occurence/Liste_occurence.h"
#include "Encodage.h"
#include "Decompress.h"

FILE* compress(FILE* fichier, Node **arbre_h,Node ** arbre_temp)
{
    Element *l=NULL;
    FILE *dictio=NULL;
    FILE *Encodage=NULL;
    fopen_s(&dictio,"dictionnaire.txt","r+");
    l=occurence(fichier);
    *arbre_h = arbre_huffman(l);
    fseek (fichier,0,SEEK_SET);
    *arbre_temp = trees_copy_tree(*arbre_h);
    dictionnaire(dictio, *arbre_temp, l);
    fseek (dictio,0,SEEK_SET);
    fseek (fichier,0,SEEK_SET);
    Encodage = encodage(dictio,fichier);
    free_tab(l);
    free_node(*arbre_temp);
    fclose(dictio);
    return Encodage;

}

