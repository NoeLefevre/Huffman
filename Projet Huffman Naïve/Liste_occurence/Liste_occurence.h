#ifndef LISTE_OCCURENCE_H_INCLUDED
#define LISTE_OCCURENCE_H_INCLUDED
#include "../Structure/Structure.h"


Element* creer_el(char nouv_char);
void ajouter_el_fin(Element** liste, Element* el);
int list_position2(Element* l,char p);
Element* occurence(FILE *fichier);

#endif // LISTE_OCCURENCE_H_INCLUDED
