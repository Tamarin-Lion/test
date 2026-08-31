/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 00:06:15 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/27 00:23:12 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_sort(char *str)
{
	int	i;
	int 	j;
	int	len;
	char	tmp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[i] > str[j + 1])
			{
				tmp = str[i];
				str[i] = str[j + 1];
				str[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	int	i;
	int	c;

	c = 1;
	(void)ac;
	while (av[c])
	{
		i = 0;
		ft_sort(av[c]);
		while (av[c][i])
		{
			write(1, &av[c][i], 1);
			i++;
		}
		c++;
	}
}
