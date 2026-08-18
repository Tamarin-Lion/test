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
#include <string.h>

int	ft_strlen(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

int	total_length(int size, char **strs, char *sep)
{
	int	length;

	while (size > 0)
	{
		length += ft_strlen(strs[size]);
		if (size > 1)
			length += ft_strlen(sep);
		size--;
	}
	return (length);
}

char	*fill(int size, char **strs, char *sep, char *join)
{
	int	i;
	int	sz;

	i = 0;
	sz = 0;
	while(*strs[sz])
	{
		i = 0;
		while (strs[sz][i])
		{
			join[i] = strs[sz][i];
			i++;
		}
		if (*strs[sz] != *strs[size])
		{
			i = 0;
			while (sep[i])
			{
				join[i] = sep[i];
				i++;
			}
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
	join = malloc(total_length(size, strs, sep) * sizeof(char) + 1);
	if (join == NULL)
		return (NULL);
	*join = *fill(size, strs, sep, join);
	while (join[i])
		i++;
	join[i] = '\0';
	return (join);
}

#include <stdio.h>

int main()
{
	char *sep = " . ";
	char *tab[5] = {"Puissant", "comme", "esprit", "de", "conquete"};
	int size;

	size = 5;
	printf("%s\n", ft_strjoin(size, tab, sep));
}
