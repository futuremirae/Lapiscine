/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeosong <myeosong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:18:14 by myeosong          #+#    #+#             */
/*   Updated: 2023/07/30 16:19:11 by dongyeuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	check(int idx1, int idx2, int ans[4][4], int trgt[4][5]);
int		check_cross(int idx1, int idx2, int ans[4][4]);
int		check_up(int col, int ans[4][4], int trgt[4][5]);
int		check_down(int col, int ans[4][4], int trgt[4][5]);
int		check_left(int row, int ans[4][4], int trgt[4][5]);
int		check_right(int row, int ans[4][4], int trgt[4][5]);

void	print_building(int ans[4][4], int trgt[4][5])
{
	int		i;
	int		j;
	char	num;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num = '0' + ans[i][j];
			write(1, &num, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	trgt[3][4] = 1;
}

void	dfs(int idx1, int idx2, int ans[4][4], int trgt[4][5])
{
	int	i;

	i = 0;
	while (++i <= 4)
	{
		ans[idx1][idx2] = i;
		if (trgt[3][4])
			return ;
		if (check_cross(idx1, idx2, ans))
		{
			check(idx1, idx2, ans, trgt);
		}
	}
	ans[idx1][idx2] = -1;
}

void	check(int idx1, int idx2, int ans[4][4], int trgt[4][5])
{
	if (idx1 < 3 && idx2 == 3)
	{
		if (check_left(idx1, ans, trgt) && check_right(idx1, ans, trgt))
			dfs(idx1 + 1, 0, ans, trgt);
	}
	else if (idx1 == 3 && idx2 <= 3)
	{
		if (check_up(idx2, ans, trgt) && check_down(idx2, ans, trgt))
		{
			if (idx1 == 3 && idx2 == 3)
			{
				if (check_left(3, ans, trgt) && check_right(3, ans, trgt))
				{
					print_building(ans, trgt);
					return ;
				}	
			}
			dfs(idx1, idx2 + 1, ans, trgt);
		}
	}
	else if (idx1 < 3 && idx2 < 3)
		dfs(idx1, idx2 + 1, ans, trgt);
}
