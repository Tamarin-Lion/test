/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:07:23 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/18 19:53:42 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *l)
{
	int	i;

	i = 0;
	while (l[i] != '\0')
		i++;
	return (i);
}

int	total_length(int size, char **strs, char *sep)
{
	int	length;

	while (size > 0)
	{
		size--;
		length += ft_strlen(strs[size]);
		if (size > 1)
			length += ft_strlen(sep);
	}
	return (length);
}

char	*add_sep(char *join, char *sep, int i)
{
	int	c;

	c = 0;
	while (sep[c])
	{
		join[i] = sep[c];
		c++;
		i++;
	}
	return (join);
}

char	*fill(int size, char **strs, char *sep, char *join)
{
	int	c;
	int	i;
	int	sz;

	i = 0;
	sz = 0;
	c = 0;
	while(*strs[sz])
	{
		c = 0;
		while (strs[sz][c])
		{
			join[i] = strs[sz][c];
			i++;
			c++;
		}
		if (*strs[sz] != *strs[size])
		{
			add_sep(join, sep, i);
		}
		sz++;
	}
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;

	i = 0;
	if (size <= 0)
	{
		join = malloc(1);
		join[0] = '\0';
		return (join);
	}
	else
	{
		join = malloc(sizeof(char) * total_length(size, strs, sep) + 1);
		if (join == NULL)
			return (NULL);
		*join = *fill(size, strs, sep, join);
		while (join[i])
			i++;
		join[i + 1] = '\0';
		return (join);
	}
}

#include <stdio.h>

int main()
{
	char *sep = " . ";
	char *tab[5] = {"Puissant", "comme", "esprit", "de", "conquete"};
	char *joinres;
	int size;
	int i = 0;

	size = 5;
	joinres = ft_strjoin(size, tab, sep);
	while (joinres[i])
	{
		printf("%c", joinres[i]);
		i++;
	}
	free(joinres);
	//printf("%s\n", joinres);
}
