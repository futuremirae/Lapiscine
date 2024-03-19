/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkim <mirkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:16:15 by mirkim            #+#    #+#             */
/*   Updated: 2023/07/26 16:13:03 by mirkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size / 2)
	{
		temp = tab[size - 1 - i];
		tab[size - 1 - i] = tab[i];
		tab[i] = temp;
		i++;
	}
}	
