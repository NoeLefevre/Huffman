#include <stdio.h>
#include <stdlib.h>
#include "Compress-decompresse/compress.h"
#include "Compress-decompresse/Decompress.h"
#include <time.h>
#include "Structure/Structure.h"


void print_liste_chaine(Element *maListe)
{
    Element* temp;
	temp = maListe;
	while (temp != NULL)
    {
		printf("%c | %d->", temp->charactere,temp->data);
		temp = temp->next;
	}
    printf("X\n");
}







void print_test_arbre(List_node *l)
{
    List_node *temp=l;
    while (temp!=NULL)
    {
        printf("%d ",temp->no->data);
        temp = temp->next;
    }
}



void print_tree(Node *tree)
{
    if (tree!=NULL)
    {
        printf("%c|%d ",tree->charactere,tree->data);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}





void print_array(char*l)
{
    int i=0;
    while (l[i]!='\0')
    {
        printf("%c",l[i]);
        i++;
    }
}

void print_l(Element *l)
{
    Element *temp = l;
    while (temp!=NULL)
    {
        printf("%c|%d ",temp->charactere,temp->data);
        temp = temp->next;
    }
}






int main()
{

    //int nbr1;
    //int nbr2;
    FILE *fichier2 = NULL;
    FILE *fichier = NULL;
    Node *arbre_h=NULL;
    Node *arbre_temp=NULL;
    FILE* f = NULL;
    FILE* trad = NULL;
    clock_t t1;
    clock_t t2;
    int choix;
    long clk_tck = CLOCKS_PER_SEC;
    fopen_s(&fichier2,"fichier2.txt","w+");
    fopen_s(&fichier,"fichier.txt","r+");
    //conversion(fichier,fichier2);
    do
    {
        printf("Veuillez rentrer un fichier a compresser, tapez 1 lorsque c'est fait, si vous voulez quitter tapez 0");
        scanf("%d",&choix);
    }while (choix!=1 && choix!=0);
    if (choix==1)
    {
        if (fgetc(fichier)==EOF)
            printf("Vous n'avez pas rentre de fichier a compresser");
        else
        {
            fseek (fichier,0,SEEK_SET);
            fseek (fichier2,0,SEEK_SET);
            t1 = clock();
            f = compress(fichier,&arbre_h,&arbre_temp);
            t2 = clock();
            printf("Temps de compression = %lf s\n", (t2 - t1) / (double)clk_tck);
            fseek (f,0,SEEK_SET);
            t1 = clock();
            trad = decompress(f, arbre_h);
            t2 = clock();
            printf("Temps de decompression = %lf s\n", (t2 - t1) / (double)clk_tck);
            fseek (f,0,SEEK_SET);
            free_node(arbre_h);
            //nbr1 = nbr_caractere(fichier2);
            //nbr2 = nbr_caractere(f);
            fclose(f);
            fclose(fichier);
            fclose(fichier2);
            //printf("Nombre de caracteres dans le fichier non compresse : %d\nNombre de caracteres dans le fichier compresse : %d\n",nbr1,nbr2);
            fseek(trad, 0, SEEK_SET);
            //nbr2 = nbr_caractere(trad);
            fclose(trad);
            //printf("Nombre de caracteres dans le fichier non compresse : %d\nNombre de caracteres dans le fichier decompresse : %d", nbr1, nbr2);
        }

    }

}







