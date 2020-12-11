#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste_occurence.h"
#include "../Liberation/Liberation.h"
Element* creer_el(char nouv_char)//Ou Element* creer_el(int nouv_info)
{
	Element * nouv_elem;//Ou Element* nouv_elem ...etc
	nouv_elem = (Element*)malloc(sizeof(Element));
	nouv_elem->data = 1;
    nouv_elem->charactere = nouv_char;
	nouv_elem->next = NULL;
	return nouv_elem;
}


void ajouter_el_fin(Element** liste, Element* el){
    Element* temp = *liste;
    if (*liste == NULL){
        *liste = el;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = el;
    }

}

int list_position2(Element* l,char p){//Cette fonction permet de détecter la présence d'un élément dans la liste
    int i=1;
    Element *temp;
    temp = l;
    while (temp!=NULL && (int)temp->charactere!=(int)p)//on effectue la boucle si la case suivante existe et tant qu'on n'a pas détecté l'élément recherché
    {
    i++;
    temp = temp->next;
    }
    if (temp == NULL)//on arrive à la fin et on ne l'a pas détecté
        return -1;
    else
        return i;//on renvoie la position de l'élément

}

Element* occurence(FILE *fichier)
{
    char c;
    int i=0;
    Element *l=NULL;
    do
    {
        c = fgetc(fichier);
        if (c!=EOF)
        {
            if (l==NULL || list_position2(l,c)==-1)//si l'élément n'est pas dans la liste (on se sert de la fonction list_position pour le détecter) :
            {
            Element *nouv_el = creer_el(c);
            ajouter_el_fin(&l,nouv_el);//On se sert des deux fonctions creer_el et ajouter_el_fin pour créer l'élément et l'ajouter en tête de liste
            }
            else//si l'élément est dans la liste
            {
                Element *temp=l;
                for (i=0;i<list_position2(l,c)-1;i++)//on va jusqu'à sa position
                {
                    temp = temp->next;//on l'incrémente
                }
            temp->data++;
            }
        }
    }while (c!=EOF);
    return l;
}
