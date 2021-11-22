#include <stdlib.h>

char	*my_strndup(char const *s, int n)
{
	char	*dst;
	int	i = 0;

        if (n < 0)
            n = 0;
	if (!s || !(dst = malloc((n + 1) * sizeof(char))))
		return (0);
        for (int j = 0 ; j < n + 1 ; j++)
            dst[j] = 0;
	while (s[i] && i < n && s[i] != '\n')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
