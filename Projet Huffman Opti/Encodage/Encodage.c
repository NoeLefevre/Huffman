#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encodage.h"


char* nbr_recherche_arbre_recherche(Node_d *tree,char c)
{
    if (tree->charactere==c)
    {
        return tree->code;
    }
    else
    {
        if (tree->charactere<c)
            tree = tree->right;
        else
            tree = tree->left;
        return nbr_recherche_arbre_recherche(tree,c);
    }
}

FILE *encodage(FILE *fichier,Node_d *tree)
{
    FILE *fichier2=NULL;
    fichier2 = fopen("Encodeur.txt","w+");
    char c=fgetc(fichier);
    while (c!=EOF)
    {
        fprintf(fichier2,"%s",nbr_recherche_arbre_recherche(tree,c));
        c=fgetc(fichier);
    }
    return fichier2;
}
