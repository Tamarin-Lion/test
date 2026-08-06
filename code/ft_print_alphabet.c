/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:18:45 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/06 17:42:17 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_print_alphabet(void)
{
	int counter;
	counter = 26;
	//counter = 0
	char letter;
	letter = 97;

	while(counter > 0/*ou < 26*/)
	{
		printf(&letter);
		letter++;
		counter--;
	}
}

int	main()
{
	ft_print_alphabet;
}
