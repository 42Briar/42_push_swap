#include "pushswap.h"

bool	checkarg(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == 0)
			return (false);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (false);
			if ((argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])) || \
			(argv[i][j] == '-' && ft_isdigit(argv[i][j - 1])))
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
		b[i].index = -1;
		i++;
	}
	return (b);
}

t_elems	*inita(int argc, char **argv, t_elems *a)
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
		a[i].index = -1;
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

	if (argc == 1)
		exit(0);
	a = (t_elems *)malloc(sizeof(t_elems) * argc - 1);
	if (!a)
		exit(0);
	b = (t_elems *)malloc(sizeof(t_elems) * argc - 1);
	if (!b)
		exit(0);
	a = inita(argc, argv, a);
	b = initb(b, argc);
	if (argc == 2)
		exit(0);
	indexstack(a);
	if (checkorder(a))
		exit(0);
	solve_decide(argc, a, b);
	exit(0);
}
