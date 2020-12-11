#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste_occurence.h"
void list_insert(Element** l,char n, int pos){
    if (l!=NULL)
    {
        if (*l==NULL || pos<=0)
        {
            Element *temp=*l;
            (*l) = malloc(sizeof(Element));
            (*l)->charactere = n;
            (*l)->data = 1;
            (*l)->next = temp;
        }
        else
            list_insert(&((*l)->next),n,pos-1);
    }
}


int list_size(Element *l)
{
    int i=-1;
    Element* temp;
    temp = l;
    while (temp != NULL)
    {
        i = i + 1;
        temp=temp->next;
    }
    temp = NULL;
    free(temp);
    return i;
}

Element* recherche_element(Element *liste,int pos)
{
    if (pos==0 || pos<0)
        return liste;
    else
        return recherche_element(liste->next,pos-1);

}
Element *occurence_trie(FILE *fichier)
{
    Element *tab = NULL;
    Element *temp;
    char c;
    int test=0;
    do
    {
        c = fgetc(fichier);
        if (c!=EOF)
        {
            test = 0;
            int a = 0;
            int b = list_size(tab);
            int p=(a+b)/2;
            if (tab!=NULL)
            {
                while ((a<b) && test==0)
                {
                    temp = recherche_element(tab,p);
                    if (temp->charactere==c)
                    {
                        test = 1;
                        temp->data++;
                    }
                    else if (temp->charactere > c)
                    {
                        if (b!=a+1)
                            b = p-1;
                        else
                            b = p;
                    }
                    else
                    {
                       a = p+1;
                    }
                    if(a<=b)
                        p = (a+b)/2;
                }
                if (test==0)
                {
                    temp = recherche_element(tab,p);
                    if (temp->charactere==c)
                        temp->data++;
                    else if (c<temp->charactere)
                        list_insert(&tab,c,p);
                    else
                        list_insert(&tab,c,p+1);

                }
            }
            else
            {
                tab = malloc(sizeof(Element));
                tab->charactere = c;
                tab->data = 1;
                tab->next = NULL;
            }

        }
    }while (c!=EOF);
    return tab;

}

void tri_a_bulle(Element **l)
{
    int fin=0;
    Element *temp=*l;
    while(fin==0)
    {
        fin = 1;
        temp = *l;
        while (temp->next!=NULL)
        {
            if (temp->data>temp->next->data)
            {
                list_swap(l,temp,temp->next);
                fin = 0;
            }
            else
                temp = temp->next;

        }
    }
    temp = NULL;
}

void list_swap(Element** l, Element* t1, Element* t2){
    Element *temp=*l;
    Element *temp2=*l;
    Element* temp5;
    if (list_size(*l)==1)
    {
        temp2 = temp;
        temp = temp->next;
        temp2->next = NULL;
        temp->next = temp2;
    }
    else
       if (t1==*l || t2==*l)
        {
            if (t1==*l)
            {
                temp = t1;
                temp2 = t2;
            }
            else
            {
                temp = t2;
                temp2 = t1;
            }

            temp5 = temp2->next;
            *l = temp2;
            temp2->next = temp;
            temp2->next->next = temp5;
        }

    else
        {
            while (temp->next!=t1 || temp2->next!=t2)
        {
            if (temp->next!=t1)
            {
                temp = temp->next;

            }
            if (temp2->next!=t2)
            {
                temp2 = temp2->next;
            }
        }
        temp5 = temp2->next->next;
        temp->next = temp2->next;
        temp->next->next = temp2;
        temp2->next = temp5;
        }

}
