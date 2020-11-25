#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decompress.h"


FILE *decompress(FILE* fichier,Node *tree)
{
    char c;
    int i;
    Node *temp=tree;
    FILE *trad=NULL;
    trad = fopen("trad.txt","w+");
    int *nb_binaire=malloc(8*sizeof(int));
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
                nb_binaire = binaire (nb_binaire,(int)temp->charactere);
                for (i=0;i<8;i++)
                {
                    fprintf(trad,"%d",nb_binaire[i]);
                }
                temp = tree;
            }

        }
    }while (c!=EOF);
    return trad;
}
