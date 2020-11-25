#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

FILE *compress(FILE* fichier)
{
    Element *l=NULL;
    Node *arbre_h=NULL;
    Node *arbre_temp=NULL;
    FILE *dictio=NULL;
    FILE *f=NULL;
    FILE *trad=NULL;
    dictio = fopen("dictionnaire.txt","r+");
    l=occurence(fichier);
    arbre_h = arbre_huffman(l);
    fseek (fichier,0,SEEK_SET);
    arbre_temp = trees_copy_tree(arbre_h);
    dictionnaire(dictio,arbre_temp,l);
    fseek (dictio,0,SEEK_SET);
    fseek (fichier,0,SEEK_SET);
    f = encodage(dictio,fichier);
    return f;
    /*
    fseek (f,0,SEEK_SET);
    trad = decompress(f,arbre_h);
    return trad;
    */
}
FILE *compress2(FILE* fichier)
{
    Element *l=NULL;
    Node *arbre_h=NULL;
    Node *arbre_temp=NULL;
    FILE *dictio=NULL;
    FILE *f=NULL;
    FILE *trad=NULL;
    dictio = fopen("dictionnaire.txt","r+");
    l=occurence(fichier);
    arbre_h = arbre_huffman(l);
    fseek (fichier,0,SEEK_SET);
    arbre_temp = trees_copy_tree(arbre_h);
    dictionnaire(dictio,arbre_temp,l);
    fseek (dictio,0,SEEK_SET);
    fseek (fichier,0,SEEK_SET);
    f = encodage(dictio,fichier);
    //return f;
    fseek (f,0,SEEK_SET);
    trad = decompress(f,arbre_h);
    return trad;
}
