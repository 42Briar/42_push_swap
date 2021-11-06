#include "pushswap.h"

bool	checkarg(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	checkint(t_elems *a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i].number == a[j].number)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_elems	*initb(t_elems *b, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		b[i].number = 0;
		b[i].store = false;
		b[i].len = argc - 1;
		i++;
	}
	return (b);
}

t_elems	*inita(int argc, char **argv, t_elems *a, int test)
{
	int		i;
	long	temp;

	i = 0;
	if (!checkarg(argv, argc))
		terminate();
	while (i < argc - 1)
	{
		temp = (long)ft_atoi(argv[i + 1]);
		if (temp > 2147483647 || temp < -2147483648)
			terminate();
		a[i].number = (int)temp;
		a[i].store = true;
		a[i].len = argc - 1;
		i++;
	}
	if (!checkint(a, argc - 1))
		terminate();
	return (a);
}

int	main(int argc, char *argv[])
{
	t_elems	*a;
	t_elems	*b;

	if (argc == 2)
		solved(a);
	a = (t_elems *)malloc(sizeof(t_elems) * argc - 1);
	b = (t_elems *)malloc(sizeof(t_elems) * argc - 1);
	a = inita(argc, argv, a, 1);
	b = initb(b, argc);
	if (checkorder(a))
		solved(a);
	if (argc == 3)
		solve_2(a);
	if (argc == 4)
		solve_3(a);
	else if (argc > 4)
		sort(a, b);
	solved(a);
	// shitsolver(a, b);
	// while (b[0].store != false)
	// 	pa(a, b);
	// solved(a);
}
