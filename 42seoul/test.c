/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirkim <mirkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:53:29 by mirkim            #+#    #+#             */
/*   Updated: 2023/07/27 21:58:20 by mirkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	flag(int i, char *str);

char *ft_strcapitalize(char *str)
{
	int	i;

	i = 1;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	
	while(str[i])
	{	
		if(flag(i-1, str))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		}
		else 
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		} 
		i++;
		flag(i, str);
	}
	return (str);
}

int	flag(int i, char *str)
{
	if (str[i]>= 'a' && str[i] <= 'z')
		return (0);
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	if ( str[i] >='A' && str[i] <= 'Z')
		return (0);
	else
		return (1);
}
#include <stdio.h>
#include <string.h>
int	main(void)
{
printf("-ex09_test_case-\n\n");
	char test10[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char test13[] = "ASLD masldw+ ?lsa 3wmdalASDzqp asm sdk2sk";
	printf("before : %s\n\n", test10);
	ft_strcapitalize(test10);
	printf("after : %s\n\n", test10);
	printf("-------------------------------\n\n");
	printf("before : %s\n\n", test13);
	ft_strcapitalize(test13);
	printf("after : %s\n\n", test13);
	printf("\n\n------------------------------\n\n");
}









