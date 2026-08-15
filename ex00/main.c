/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:23:54 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/15 17:38:18 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_comb(char *str);

int	ft_check_input(char *c)
{
	int	i;
	int	cint;
	int	cspc;

	i = 0;
	cint = 0;
	cspc = 0;
	while (c[i])
	{
		if (!((c[i] >= '1' && c[i] <= '4') || c[i] == ' '))
		{
			write (2, "Error : input not valid\n", 24);
			return (0);
		}
		if ((c[i] >= '1' && c[i] <= '4') && (c[i + 1] == ' ' || c[i - 1] == ' '))
			cint++;
		if (c[i] == ' ')
			cspc++;	
		i++;
	}
	if (c[31] != '\0')
	{
		write (2, "Error : string doesn't contain 32 characters\n", 45);
	}
	if (cint == 16 && cspc == 15)
		return (1);
	else
	{
		write (2, "Error : characters not valid\n", 29);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	char inp[31];
	int i;

	i = 0;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < 31)
	{
		inp[i] = argv[1][i];
		i++;
	}
	if (ft_check_input(inp))
		ft_comb(inp);
	else
		return(0);
}
