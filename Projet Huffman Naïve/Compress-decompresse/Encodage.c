#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encodage.h"
#include "../Liberation/Liberation.h"
FILE *encodage(FILE *dictio,FILE *fichier)
{
    FILE *fichier2=NULL;
    fopen_s(&fichier2,"Encodeur.txt","w+"); //On ouvre le fichier dans lequel on va écrire le résultat de notre encodage
    char* p  = malloc(20*sizeof(char)); //Liste qui prendre le code d'un caractère
    char c=fgetc(fichier); 
    char c2;
    int test=1;
    int test2=1;
    while (c != EOF) //Tant qu'on est pas à la fin du fichier à encoder
    {
        test = 1;
        while (test2 == 1 && test == 1) //On parcours le dictionnaire jusqu'à trouver le bon caractère 
        {
            c2 = fgetc(dictio); //On prend un caractère dans le dictionnaire
            fseek(dictio, 1, SEEK_CUR); //On déplace le curseur dans le fichier de un pas afin d'éviter les : pour ne pas les prendre avec le fgetc
            if (fgets(p, 20, dictio) == NULL) //Cas où on est à la fin du fichier et qu'il n'y a plus de code
                test = 0;
            if (test == 1)
            {
                if ((int)c == (int)c2) //Si on trouve le caractère recherché
                {
                    //printf("%s",p);
                    test = 0;
                    p[strlen(p) - 1] = '\0'; //On mesure la longueur du code du caractère
                    fprintf(fichier2, "%s", p); //On print le code du caractère dans le fichier encodage
                }
            }
        }
        c = fgetc(fichier); //On avance le curseur dans le fichier à encoder pour re-parcourir le dictionnaire à la recherche du caractère suivant
        fseek(dictio, 0, SEEK_SET); //On remet le curseur au début dans le dictionnaire
        //printf("%c",c);
    }
    free(p); 
    return fichier2;
}
