#include "pushswap.h"

void	pa(t_elems *a, t_elems *b)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	if (!b[0].store)
		return ;
	write(1, "pa\n", 3);
	while (a[i].store != false && i < a[i].len)
		i++;
	while (i >= 0)
	{
		a[i].number = a[i - 1].number;
		a[i].store = true;
		i--;
	}
	a[0].number = b[0].number;
	i = 0;
	while (b[i].store != false && i < b[i].len)
	{
		b[i].number = b[i + 1].number;
		i++;
	}
	b[i - 1].store = false;
}

void	pb(t_elems *a, t_elems *b)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	if (!a[0].store)
		return ;
	write(1, "pb\n", 3);
	while (b[i].store != false && i < b[i].len)
		i++;
	while (i >= 0)
	{
		b[i].number = b[i - 1].number;
		b[i].store = true;
		i--;
	}
	b[0].number = a[0].number;
	i = 0;
	while (a[i].store != false && i < a[i].len)
	{
		a[i].number = a[i + 1].number;
		i++;
	}
	a[i - 1].store = false;
}
