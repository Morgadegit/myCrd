/*
** ETNA PROJECT,  
** FILENAME
** File description:
**		
*/

#include "my_crd.h"

t_node *my_new_node(char *key, char *value, t_node **list)
{
    t_node       *new;

    if (!(new = malloc(sizeof(t_node))))
        return NULL;
    new->key = key;
    new->value = value;
    new->next = NULL;
    if ((*list) == NULL)
    {
        *list = new;
        (*list)->prev = NULL;
        return new;
    }
    while ((*list)->next)
        (*list) = (*list)->next;
    new->prev = (*list);
    (*list)->next = new;
    return new;
}
