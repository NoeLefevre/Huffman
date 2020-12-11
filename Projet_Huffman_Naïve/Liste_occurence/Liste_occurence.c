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

int list_position2(Element* l,char p){
    int i=1;
    Element *temp;
    temp = l;
    while (temp!=NULL && (int)temp->charactere!=(int)p)
    {
    i++;
    temp = temp->next;
    }
    if (temp == NULL)
        return -1;
    else
        return i;

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
            if (l==NULL || list_position2(l,c)==-1)
            {
            Element *nouv_el = creer_el(c);
            ajouter_el_fin(&l,nouv_el);
            }
            else
            {
                Element *temp=l;
                for (i=0;i<list_position2(l,c)-1;i++)
                {
                    temp = temp->next;
                }
            temp->data++;
            }
        }
    }while (c!=EOF);
    return l;
}
