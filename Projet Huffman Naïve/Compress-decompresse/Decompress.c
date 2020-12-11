#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decompress.h"
#include "../Binaire/Binaire.h"
#include "../Liberation/Liberation.h"
FILE* decompress(FILE* fichier,Node *tree)
{
    char c;
    Node *temp=tree;
    FILE *trad=NULL;
    fopen_s(&trad, "trad.txt", "w+");
    do
    {
        c = fgetc(fichier);
        if (c!=EOF)
        {
            if (c=='1')
                temp = temp->right;
            else
                temp = temp->left;
            if (temp->right==NULL && temp->left==NULL)
            {
                fprintf(trad,"%c",temp->charactere);
                temp = tree;
            }

        }
    } while (c != EOF);
    return trad;
}
