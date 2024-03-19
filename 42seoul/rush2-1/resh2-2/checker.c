/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeosong <myeosong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:18:14 by myeosong          #+#    #+#             */
/*   Updated: 2023/07/30 15:58:36 by dongyeuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_cross(int idx1, int idx2, int ans[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != idx1 && ans[idx1][idx2] == ans[i][idx2])
			return (0);
		if (i != idx2 && ans[idx1][idx2] == ans[idx1][i])
			return (0);
		i++;
	}
	return (1);
}

int	check_up(int col, int ans[4][4], int trgt[4][5])
{
	int	i;
	int	current_height;
	int	count;

	i = 0;
	current_height = 0;
	count = 0;
	while (i < 4)
	{
		if (current_height < ans[i][col])
		{
			current_height = ans[i][col];
			count++;
		}
		i++;
	}
	return (count == trgt[0][col]);
}

int	check_down(int col, int ans[4][4], int trgt[4][5])
{
	int	i;
	int	current_height;
	int	count;

	i = 3;
	current_height = 0;
	count = 0;
	while (i >= 0)
	{
		if (current_height < ans[i][col])
		{
			current_height = ans[i][col];
			count++;
		}
		i--;
	}
	return (count == trgt[1][col]);
}

int	check_left(int row, int ans[4][4], int trgt[4][5])
{
	int	i;
	int	current_height;
	int	count;

	i = 0;
	current_height = 0;
	count = 0;
	while (i < 4)
	{
		if (current_height < ans[row][i])
		{
			current_height = ans[row][i];
			count++;
		}
		i++;
	}
	return (count == trgt[2][row]);
}

int	check_right(int row, int ans[4][4], int trgt[4][5])
{
	int	i;
	int	current_height;
	int	count;

	i = 3;
	current_height = 0;
	count = 0;
	while (i >= 0)
	{
		if (current_height < ans[row][i])
		{
			current_height = ans[row][i];
			count++;
		}
		i--;
	}
	return (count == trgt[3][row]);
}
