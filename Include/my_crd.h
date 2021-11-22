#ifndef MY_CRD_H
# define MY_CRD_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
    char *key;
    char *value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_parsed
{
    char *key;
    char *value;
} t_parsed;

t_node  *my_new_node(char *key, char *value, t_node **list);
char    *my_strndup(char *s, int n);
char    *my_strdup(char *s);
void    my_putstr(char *s);
int     my_strcmp(char *s1, char *s2);

#endif
