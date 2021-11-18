#include "pushswap.h"

static void	parttwo(t_elems *a, t_elems *b, int i, int len)
{
	while (b[i].store == true && i <= len)
		i++;
	b[i].store = true;
	while (i > 0)
	{
		b[i].number = b[i - 1].number;
		b[i].index = b[i - 1].index;
		i--;
	}
	i = 0;
	b[0].number = a[0].number;
	b[0].index = a[0].index;
	b[0].store = true;
	while (a[i].store == true && i <= len)
	{
		a[i].number = a[i + 1].number;
		a[i].index = a[i + 1].index;
		i++;
	}
	a[i - 1].store = false;
}

static void	push(t_elems *a, t_elems *b)
{
	int	i;
	int	len;

	i = 0;
	len = a[0].len;
	if (b[0].store == false)
	{
		b[0].number = a[0].number;
		b[0].index = a[0].index;
		b[0].store = true;
		while (a[i].store == true && i <= len)
		{
			a[i].number = a[i + 1].number;
			a[i].index = a[i + 1].index;
			i++;
		}
		a[i - 1].store = false;
		return ;
	}
	parttwo(a, b, i, len);
}

void	pa(t_elems *a, t_elems *b)
{
	write(1, "pa\n", 3);
	push(b, a);
}

void	pb(t_elems *a, t_elems *b)
{
	write(1, "pb\n", 3);
	push(a, b);
}
