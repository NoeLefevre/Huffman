#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liberation.h"

void free_tab(Element* tab)
{
    if (tab != NULL)
    {
        free_tab(tab->next);
        free(tab);
    }
}

void free_tab2(List_node* tab)
{
    if (tab != NULL)
    {
        free_tab2(tab->next);
        free(tab);
    }
}
void free_node(Node* tree)
{
    if (tree!= NULL)
    {
        free_node(tree->left);
        free_node(tree->right);
        free(tree);
    }
}


void free_stack(Stack* p)
{
    if (p != NULL)
    {
        free_stack(p->next);
        free(p);
    }
}
