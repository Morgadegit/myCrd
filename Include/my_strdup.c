/*
** ETNA PROJECT, 2021
** my_strdup.c
** File description
**      Allocates and duplicates a string
*/

#include <stdlib.h>

int     my_strlen(char const *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

char    *my_strdup(char const *s)
{
    char    *dst;
    int     i = 0;

    if (!s || !(dst = malloc(my_strlen(s) * sizeof(char) + 1)))
        return (0);
    while (s[i])
    {
        dst[i] = s[i];
        i++;
    }
    dst[i] = 0;
    return (dst);
}
