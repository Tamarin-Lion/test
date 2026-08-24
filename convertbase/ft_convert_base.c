#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str);
int	pwr(int nb, int pwr);
int	ft_length(char *l);
int	check_base(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	tlen;
	char	*res;

	tlen = ft_len(nbr) * ft_len(base_to);
	i = 0;
	res = malloc(sizeof(char) * );
	if(!(check_base(base_from)))
}

int	main(int ac, char **av)
{
	if (ac != 2)
		printf("Manque d'arguments");
	else
	{
		check_base(av[1]);
	}
}
