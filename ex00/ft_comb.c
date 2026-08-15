/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:32:09 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/15 18:46:34 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_line(char *rowleft, char *rowright)
{
	int	rl;
	int	rr;
	int	add;
	int	i;
	
	i = 0;
	while (i < 4)
	{
		rl = rowleft[i] - '0';
		rr = rowright[i] - '0';
		add = rr + rl;
		if (add < 3 || add > 5)
		{
			write(2, "Error : rows not solvable\n", 26);
			return ;
		}
		i++;
	}
}

void	ft_col(char *colup, char *coldown)
{
	int	colu;
	int	cold;
	int	add;
	int	i;

	i = 0;
	while (i < 4)
	{
		colu = colup[i] - '0';
		cold = coldown[i] - '0';
		add = colu + cold;
		if (add < 3 || add > 5)
		{
			write(2, "Error : column not solvable\n", 28);
			return ;
		}
		i++;
	}
}

char	ft_save(char *c, char *str, int i)
{
	int	j;
	int	tmp;
	
	tmp = i;
	j = 0;
	while (j < 4)
        {
                 c[j] = str[tmp];
                 j++;
                 tmp += 2;
        }
        c[4] = '\0';
	return (*c);
}

void	ft_comb(char *str)
{
	char	colup[5];
	char	coldown[5];
	char	rowleft[5];
	char	rowright[5];
	int	i;
	
	i = 0;
	ft_save(colup, str, i);
	printf("%s\n", colup);
	i = 8;
	ft_save(coldown, str, i);
	printf("%s\n", coldown);
	i = 16;
	ft_save(rowleft, str, i);
	printf("%s\n", rowleft);
	i = 24;
	ft_save(rowright, str, i);
	printf("%s\n", rowright);
	ft_line(rowleft, rowright);
	ft_col(colup, coldown);
}
