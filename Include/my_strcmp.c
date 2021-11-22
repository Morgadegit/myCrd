/*
** ETNA PROJECT, 2021
** my_strcmp.c
** File description :
**      Compares two strings lexically
*/

int     my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i])
    {
        if (s2[i] != s1[i])
            break;
        i++;
    }
    return (s1[i] - s2[i]);
}
