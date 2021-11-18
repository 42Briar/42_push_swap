#include "pushswap.h"

void	indexstack(t_elems *s)
{
	int		small;
	int		temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < s[0].len)
	{
		j = -1;
		small = INT32_MAX;
		while (s[++j].store == true)
		{
			if (s[j].index > -1)
				continue ;
			else if (small >= s[j].number)
			{
				small = s[j].number;
				temp = j;
			}
		}
		s[temp].index = i;
		i++;
	}
}

void	sort(t_elems *a, t_elems *b)
{
	size_t	i;
	int		index;

	index = 0;
	while (!checkorder(a))
	{
		i = 0;
		while (i < a[0].len)
		{
			if ((a[0].index >> index) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b[0].store == true)
			pa(a, b);
		index++;
	}
}

// for (int x = 0; a[x].store == true; x++)
// 	printf("%d/", a[x].number);
// printf("\n");
// for (int x = 0; a[x].store == true; x++)
// 	printf("%d/", a[x].index);
