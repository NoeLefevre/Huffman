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

void free_node(Node* tree)
{
    if (tree!= NULL)
    {
        free_node(tree->left);
        free_node(tree->right);
        free(tree);
    }
}

void free_node2(Node_d* tree)
{
    if (tree != NULL)
    {
        free_node2(tree->left);
        free_node2(tree->right);
        free(tree);
    }
}

void free_queue(Queue* q)
{
    if (q != NULL)
    {
        free_queue(q->next);
        free(q);
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
