#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encodage.h"


char* nbr_recherche_arbre_recherche(Node_d *tree,char c) //Fonction de recherche du code caractère dans un AVL
{
    if (tree->charactere==c)
    {
        return tree->code; //Si on trouve le caractère on retourne le code
    }
    else
    {
        if (tree->charactere<c) //Sinon on recherche en fonction du signe, en allant à gauche ou à droite
            tree = tree->right;
        else
            tree = tree->left;
        return nbr_recherche_arbre_recherche(tree,c);
    }
}

FILE *encodage(FILE *fichier,Node_d *tree) //Tous les codes étant déjà triés dans un AVL, l'encodage et la recherche de caractère sera beaucoup plus simple
{
    FILE *fichier2=NULL;
    fichier2 = fopen("Encodeur.txt","w+");
    char c=fgetc(fichier);
    while (c!=EOF) //Tant qu'on a pas atteitn la fin du fichier qu'on veut encoder
    {
        fprintf(fichier2,"%s",nbr_recherche_arbre_recherche(tree,c)); //On recherche le code du caractère à encoder grâce à l'AVL et on le print dans le fichier encodage
        c=fgetc(fichier); //On avance dans le fichier qu'on veut encoder
    }
    return fichier2;
}
