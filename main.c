#include "pushswap.h"

void	terminate()
{
	write(1, "ERROR\n", 6);
	exit(0);
}

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

bool	checkint(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	*init(int argc, char **argv, int *arr)
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
		arr[i] = (int)temp;
		i++;
	}
	if (!checkint(arr, argc - 1))
		terminate();
	return (arr);
}

int	main(int argc, char *argv[])
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * argc);
	arr = init(argc, argv, arr);
}
