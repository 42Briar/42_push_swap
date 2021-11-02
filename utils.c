#include "pushswap.h"

void	terminate(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

void	solved(t_elems *a)
{
	// int	i;

	// i = 0;
	// while (i < a[i].len)
	// {
	// 	printf("%d\n", a[i].number);
	// 	i++;
	// }
	exit(0);
}

bool	checkorder(t_elems *a)
{
	int	i;

	i = 1;
	while (i < a[i].len)
	{
		if (a[i].number > a[i - 1].number)
			i++;
		else
			return (false);
	}
	return (true);
}
