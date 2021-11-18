#include "pushswap.h"

void	terminate(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

bool	checkorder(t_elems *a)
{
	int	i;

	i = 1;
	while (a[i].store == true)
	{
		if (a[i].number > a[i - 1].number)
			i++;
		else
			return (false);
	}
	return (true);
}

bool	reverseorder(t_elems *a)
{
	int	i;

	i = 1;
	while (a[i].store == true)
	{
		if (a[i].number < a[i - 1].number)
			i++;
		else
			return (false);
	}
	return (true);
}

/*
	for (int x = 0; a[x].store == true; x++)
		printf("%d/", a[x].number);
	printf("\n"); 

bool	isgreater(t_elems *a, t_elems *b)
{
	int	i;

	i = 0;
	while (b[i].store == true)
	{
		if (a[0].number > b[i].number)
			i++;
		else
			return (false);
	}
	return (true);
}

bool	islesser(t_elems *a, t_elems *b)
{
	int	i;

	i = 0;
	while (b[i].store == true)
	{
		if (a[0].number < b[i].number)
			i++;
		else
			return (false);
	}
	return (true);
}
*/