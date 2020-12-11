#include "Binaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Liberation/Liberation.h"
void conversion (FILE* fichier,FILE *fichier2)
{
    char c;
    int i;
    int *nb_binaire=malloc(8*sizeof(int));
    do
    {
        c = fgetc(fichier);
        if (c!=EOF)
        {
            nb_binaire = binaire (nb_binaire,(int)c);
        for (i=0;i<8;i++)
        {
            fprintf(fichier2,"%d",nb_binaire[i]);
        }

        }
    }while (c!=EOF);
    free(nb_binaire);
}

int* binaire(int *tab, int x)
{
    int quotient = x;
    int i=0;
    int j;
    int reste;
    while (quotient!=0)
    {
        reste = quotient%2;
        quotient = quotient/2;
        tab[7-i] = reste;
        i++;
    }
    if (i < 8)
    {
        for (j = i; j < 8; j++)
        {
            tab[7 - j] = 0;
        }
    }
    return tab;
}
int nbr_caractere(FILE* fichier)
{
    char c;
    int i=0;
    do
    {
        c = fgetc(fichier);
        if (c!=EOF)
            i++;
    }while (c!=EOF);
    return i;
}
