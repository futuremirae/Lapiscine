/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyeuk <dongyeuk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:38:17 by dongyeuk          #+#    #+#             */
/*   Updated: 2023/07/30 15:58:24 by dongyeuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_count_num(int argc, char *str, int num)
{
	int				idx;
	unsigned char	spc;
	char			tmp;

	spc = 1;
	idx = -1;
	while (str[++idx] != 0)
	{
		tmp = str[idx];
		if (tmp > '0' && tmp <= '4' && spc)
		{
			num++;
			spc = 0;
		}
		else if ((tmp == ' ' || (tmp >= 9 && tmp <= 13)) && !spc)
			spc = 1;
		else
			return (0);
	}
	if (spc || argc != 2 || num % 4 != 0 || num / 4 != 4)
		return (0);
	else
		return (num);
}

void	ft_init_array(int trgt[4][5], int ans[4][4], char *data)
{
	int	idx_x;
	int	idx_y;

	idx_x = 0;
	while (idx_x < 4)
	{
		idx_y = 0;
		while (idx_y < 4)
		{
			trgt[idx_x][idx_y] = data[idx_x * 8 + idx_y * 2] - 48;
			ans[idx_x][idx_y] = -1;
			idx_y++;
		}
		idx_x++;
	}
	trgt[3][4] = 0;
}
