#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Compress/Compress.h"
#include "Conversion/Conversion.h"
#include "Compression.h"
#include "Libération/Liberation.h"







void Compression()
{
    //int nbr1;
    //int nbr2;
    FILE* fichier = NULL;
    FILE* Encodage = NULL;
    FILE* Binaire = NULL;
    FILE* trad = NULL;
    Node* tree = NULL;
    FILE* dictio = NULL;
    Node* huff_t = NULL;
    Element* tab = NULL;
    clock_t t1;
    clock_t t2;
    long clk_tck = CLOCKS_PER_SEC;
    int x;
    do
    {
        printf("Veuillez rentrer votre fichier dans <text.txt>, appuyez sur 1 quand vous l'avez fait\n, si vous voulez quitter appuyez sur 0");
        scanf_s("%d", &x);

    } while (x != 1 && x != 0);
    fopen_s(&fichier, "text.txt", "r+");
    if (x != 0)
    {
        if (fgetc(fichier) == EOF)
        {
            printf("Vous n'avez pas entrer de fichier a compresser, veuillez recommencer l'operation");
        }
        else
        {
            fopen_s(&Binaire, "Binaire.txt", "w+");
            fopen_s(&dictio, "dictionnaire.txt", "w+");
            t1 = clock();
            Encodage = compress(&dictio, fichier, &huff_t, &tab);
            t2 = clock();
            printf("Temps de compression = %lf s\n", (t2 - t1) / (double)clk_tck);
            fseek(dictio, 0, SEEK_SET);
            free_node(huff_t);
            free_tab(tab);
            free_node(tree);
            fseek(fichier, 0, SEEK_SET);
            fseek(Encodage, 0, SEEK_SET);
            //conversion(fichier, &Binaire);
            fseek(Binaire, 0, SEEK_SET);
            fseek(dictio, 0, SEEK_SET);
            fclose(fichier);
            //nbr1 = nbr_caractere(Binaire);
            //nbr2 = nbr_caractere(Encodage);
            //printf("Nombre de caracteres dans le fichier non compresse : %d\nNombre de caracteres dans le fichier compresse : %d\n", nbr1, nbr2);
            fclose(Binaire);
            fclose(Encodage);
            fclose(dictio);
    }

    }
}
