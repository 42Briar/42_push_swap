#include "pushswap.h"

void	indexstack(t_elems *a)
{
	int i;
	int j;
	int temp;
	t_num small;
	t_num big;

	i = -1;
	temp = a[0].len / 2 + a[0].len % 2;
	while (++i < temp)
	{
		j = 0;
		small.number = INT32_MAX;
		big.number = INT32_MIN;
		while (a[j].store == true)
		{
			if (a[j].index > -1)
			{
				j++;
				continue ;
			}
			if (small.number > a[j].number)
			{
				small.number = a[j].number;
				small.index = j;
			}
			if (big.number < a[j].number)
			{
				big.number = a[j].number;
				big.index = j;
			}
			j++;
		}
		a[small.index].index = i;
		a[big.index].index = a[0].len - i - 1;
	}
}

void	sort(t_elems *a, t_elems *b)
{
	int	size;
	int	i;
	int	j;
	int max;
	int num;

	i = 0;
	indexstack(a);
	while ((((a[0].len - 1) >> max) != 0))
		 ++max;
	size = a[0].len;
	while (i < max + 1)
	{
		j = 0;
		while (j < size)
		{
			num = a[0].index;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b[0].store == true)
			pa(a, b);
		i++;
	}
	// while (!checkorder(a))
	// 	ra(a);
}

// for (int x = 0; a[x].store == true; x++)
// 	printf("%d/", a[x].number);
// printf("\n");
// for (int x = 0; a[x].store == true; x++)
// 	printf("%d/", a[x].index);

/*
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
 */