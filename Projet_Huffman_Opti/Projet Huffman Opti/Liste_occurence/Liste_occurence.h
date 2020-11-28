#ifndef LISTE_OCCURENCE_H_INCLUDED
#define LISTE_OCCURENCE_H_INCLUDED
#include "../Stucture/Structure.h"
void list_insert(Element** l,char n, int pos);
int list_size(Element *l);
Element* recherche_element(Element *liste,int pos);
Element *occurence_trie(FILE *fichier);
void tri_a_bulle(Element **l);
void list_swap(Element** l, Element* t1, Element* t2);

#endif // LISTE_OCCURENCE_H_INCLUDED
