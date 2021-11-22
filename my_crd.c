/*
 ** ETNA PROJECT,  
 ** FILENAME
 ** File description:
 **		
 */

#include "Include/my_crd.h"

t_parsed    *my_parse(char *s)
{
    int         i = 0;
    int         j = 0;
    t_parsed    *ret;

    if (!(ret = malloc(sizeof(t_parsed))))
        return NULL;
    for ( ; s[i] && (s[i] != ' ' && s[i] != '\n'); i++)
        ;
    ret->key = my_strndup(s, i);
    if (s[i] == '\n')
    {
        ret->value = my_strdup("");
        return ret;
    }
    j = i;
    for ( ; s[i]; i++)
        ;
    ret->value = my_strndup(s + j + 1, i - j);
    return ret;
}

void    my_search(t_parsed *parsed, t_node **list)
{
    for ( ; (*list) ; (*list) = (*list)->next)
    {
        if ((*list)->key && my_strcmp((*list)->key, parsed->key) == 0)
        {
            my_putstr((*list)->value);
            return;
        }
    }
    write(1, "-1", 2);
}

void    my_delete(t_parsed *parsed, t_node **list)
{
    for ( ; (*list) ; (*list) = (*list)->next)
        if ((*list)->key && my_strcmp((*list)->key, parsed->key) == 0)
        {
            my_putstr((*list)->value);
            if ((*list)->prev)
                (*list)->prev->next = (*list)->next;
            else
                (*list) = (*list)->next;
            return;
        }
    write(1, "-1", 2);
}

void    my_add(t_parsed *parsed, t_node **list)
{
    t_node *tmp = *list;
    for ( ; (*list) ; (*list) = (*list)->next)
    {
        if ((*list)->key && my_strcmp((*list)->key, parsed->key) == 0)
        {
            free((*list)->value);
            (*list)->value = my_strdup(parsed->value);
            my_putstr((*list)->key);
            return;
        }
        if (!(*list)->next)
            tmp = *list;
    }
    my_new_node(parsed->key, parsed->value, &tmp);
    my_putstr(parsed->key);
}

t_node  *my_make_bunk(void)
{
    t_node *new;

    if (!(new = malloc(sizeof(t_node))))
        return NULL;
    new->key = NULL;
    new->value = NULL;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

int     main(void)
{
    char            *line = NULL;
    t_node          *list = my_make_bunk();
    t_parsed        *parsed = NULL;
    size_t          n = 0;
    t_node          *first = list;

    while (getline(&line, &n, stdin) != -1)
    {
        parsed = my_parse(line);
        if (my_strcmp(parsed->value, "") == 0)
            my_search(parsed, &list);
        else if (my_strcmp(parsed->value, "D") == 0)
            my_delete(parsed, &list);
        else
            my_add(parsed, &list);
        free(parsed);
        parsed = NULL;
        my_putstr("\n");
        list = first;
    }
    free(line);
}
