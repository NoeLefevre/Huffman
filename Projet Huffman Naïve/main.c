#include <stdio.h>
#include <stdlib.h>
#include "Compress-decompresse/compress.h"



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

    int nbr1;
    int nbr2;
    FILE *fichier2 = NULL;
    FILE *fichier = NULL;
    FILE *f=NULL;
    fichier2 = fopen("fichier2.txt","w+");
    fichier = fopen("fichier.txt","r+");
    conversion(fichier,fichier2);
    fseek (fichier,0,SEEK_SET);
    fseek (fichier2,0,SEEK_SET);
    f = compress(fichier);
    fseek (f,0,SEEK_SET);
    nbr1 = nbr_caractere(fichier2);
    nbr2 = nbr_caractere(f);
    printf("Nombre de caracteres dans le fichier non compresse : %d\nNombre de caracteres dans le fichier compresse : %d",nbr1,nbr2);
}







