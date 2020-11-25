#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compress/Compress.h"
#include "Conversion/Conversion.h"
#include "Decompress/Decompress.h"*


/*
void print_test_arbre(Queue *l)
{
    List_node *temp=l;
    while (temp!=NULL)
    {
        printf("%d ",temp->no->data);
        temp = temp->next;
    }
}
*/










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

void print_liste_chaine2(Queue *maListe)
{
    Queue* temp;
	temp = maListe;
	while (temp != NULL)
    {
		printf("%c | %d->", temp->no->charactere,temp->no->data);
		temp = temp->next;
	}
    printf("X\n");
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



void print_test(Node_d *tree)
{
    if (tree!=NULL)
    {
        printf("%c : %s\n",tree->charactere,tree->code);
        print_test(tree->left);
        print_test(tree->right);
    }
}





int main()
{
    int nbr1;
    int nbr2;
    FILE *fichier=NULL;
    FILE *fichier2=NULL;
    FILE *fichier3=NULL;
    FILE *trad=NULL;
    Node *tree = NULL;
    FILE *dictio = NULL;
    Node *huff_2 = NULL;
    Node *huff_t=NULL;
    Element* tab = NULL;
    trad = fopen("trad.txt","r+");
    fichier = fopen("text.txt","r+");
    fichier3 = fopen("fichier3.txt","r+");
    dictio = fopen("dictionnaire.txt","r+");
    fichier2 = compress(fichier,&huff_t,&tab);
    fseek(dictio,0, SEEK_SET);
    tree = trees_copy_tree(huff_t);
    dictionnaire(dictio,tree,tab);
    fseek(fichier,0, SEEK_SET);
    fseek(fichier2,0, SEEK_SET);
    conversion(fichier,fichier3);
    fseek(fichier3,0, SEEK_SET);
    fseek(dictio,0, SEEK_SET);
    nbr1 = nbr_caractere(fichier3);
    nbr2 = nbr_caractere(fichier2);
    printf("Nombre de caracteres dans le fichier non compresse : %d\nNombre de caracteres dans le fichier compresse : %d\n",nbr1,nbr2);
    huff_2 = create_huff(dictio);
    fseek(fichier2,0, SEEK_SET);
    trad = decompress(fichier2,huff_2);
    fseek(fichier3,0, SEEK_SET);
    fseek(trad,0, SEEK_SET);
    nbr1 = nbr_caractere(fichier3);
    nbr2 = nbr_caractere(trad);
    printf("Nombre de caracteres dans le fichier non compresse : %d\nNombre de caracteres dans le fichier decompresse : %d",nbr1,nbr2);

}
