#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encodage.h"
#include "../Liberation/Liberation.h"
FILE *encodage(FILE *dictio,FILE *fichier)
{
    FILE *fichier2=NULL;
    fopen_s(&fichier2,"Encodeur.txt","w+");
    char* p  = malloc(20*sizeof(char));
    char c=fgetc(fichier);
    char c2;
    int test=1;
    int test2=1;
    while (c != EOF)
    {
        test = 1;
        while (test2 == 1 && test == 1)
        {
            c2 = fgetc(dictio);
            fseek(dictio, 1, SEEK_CUR);
            if (fgets(p, 20, dictio) == NULL)
                test = 0;
            if (test == 1)
            {
                if ((int)c == (int)c2)
                {
                    //printf("%s",p);
                    test = 0;
                    p[strlen(p) - 1] = '\0';
                    fprintf(fichier2, "%s", p);
                }
            }
        }
        c = fgetc(fichier);
        fseek(dictio, 0, SEEK_SET);
        //printf("%c",c);
    }
    free(p);
    return fichier2;
}
