#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	pwr(int	nb, int pwr)
{
	if (pwr == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	return (nb * pwr(nb, pwr - 1));
}

int	ft_atoi(char *str)
{
	int	i;
	int	ng;
	int	res;
	
	ng = 1;
	i = 0;
	while (str[i])
	{
		while (!( (str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			i++;
		if (str[i] == '-')
			ng = -ng;
		while (str[i] >= '0' && str[i] <= '9')
		{
			res =  res * 10 + (str[i] - '0');
			i++;
		}
		i++;
		return (res * ng);
	}
}

int	ft_len(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
    	int 	r;
	char *rep;

	i = 0;
	r = 0;
	while (base[i])
		i++;
	rep = malloc(sizeof(char) * i);
	if (rep == NULL)
		return (0);
	if (i < 2)
		return (0);
	while (base[r])
	{
		i = r + 1;
		while (base[i])
		{
			if (base[i] == base[r])
			{
				return (0);
			}
			i++;
		}
		r++;
	}
	return (1);
}
