#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		my_putchar(s[i]);
		i++;
	}
}
