#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Decompression.h"
#include "Compression.h"
int main()
{
    int choix;
    printf("Bienvenue dans le menu, ceci est un programme qui permet de compresser/decompresser un fichier\nVoulez-vous compresser ou decompresser un fichier?\n");
    do
    {
        printf("Tapez 1 pour compresser un fichier ou 2 pour decompresser un fichier\n");
        scanf_s("%d",&choix);
    }while (choix!=1 && choix!=2);
    if (choix==1)
    {
        Compression();
    }
    else
    {
        Decompression();
    }
}
