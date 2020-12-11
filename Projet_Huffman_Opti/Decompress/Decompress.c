#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Decompress.h"
#include "../Arbre_huffman/Arbre_huffman.h"
#include "../Conversion/Conversion.h"
Node* create_huff (FILE *dico)
{
    char c;
    char temp_c='p';
    int i=0;
    char* p  = malloc(20*sizeof(char));
    int test = 1;
    Node *tree = create_node(2,temp_c);
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
                            temp->right = create_node(2,temp_c);
                        temp = temp->right;
                    }
                    else if (p[i]=='0')
                    {
                        if (temp->left==NULL)
                            temp->left = create_node(2,temp_c);
                        temp = temp->left;
                    }
                }
                i++;
            }
            i=0;
        }


    }
    free(p);
    return tree;
}

FILE *decompress(FILE* fichier,Node *tree)
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
                fprintf(trad, "%c", temp->charactere);
                temp = tree;
            }

        }
    }while (c!=EOF);
    return trad;
}


