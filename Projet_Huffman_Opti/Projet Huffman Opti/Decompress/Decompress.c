#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decompress.h"
Node* create_huff (FILE *dico)
{
    char c;
    int i=0;
    char* p  = malloc(20*sizeof(char));
    int test = 1;
    Node *tree = create_node(2,"c");
    Node *temp = tree;
    while (test==1)
    {
        c = fgetc(dico);
        fseek(dico,1,SEEK_CUR);
        if (fgets(p,20,dico)==NULL)
            test = 0;
        if (test==1)
        {
            p[strlen(p)-1] = '\0';
            while (p[i]!= '\0')
            {
                if (p[i+1]=='\0')
                {
                    if (p[i]=='0')
                    {
                        temp->left = create_node(2,c);
                        temp = tree;
                    }
                    else
                    {
                        temp->right = create_node(2,c);
                        temp = tree;
                    }
                }
                else
                {
                    if (p[i]=='1')
                    {
                        if (temp->right==NULL)
                            temp->right = create_node(2,"c");
                        temp = temp->right;
                    }
                    else if (p[i]=='0')
                    {
                        if (temp->left==NULL)
                            temp->left = create_node(2,"c");
                        temp = temp->left;
                    }
                }
                i++;
            }
            i=0;
        }


    }
    return tree;
}

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
