/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                           :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyeuk <dongyeuk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:47:16 by dongyeuk          #+#    #+#             */
/*   Updated: 2023/07/31 22:16:26 by mirkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	dfs(int idx1, int idx2, int ans[4][4], int trgt[4][5]);
int		ft_count_num(int argc, char *str, int num);
void	ft_init_array(int trgt[4][5], int ans[4][4], char *data);

int	main(int argc, char *args[])
{
	int			trgt[4][5];
	int			ans[4][4];
	const int	num = ft_count_num(argc, args[argc - 1], 0) / 4;

	if (num == 4)
	{
		ft_init_array(trgt, ans, args[1]);
	}
	if (num != 4)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	dfs(0, 0, ans, trgt);
	if (!trgt[3][4])
		write(1, "Error\n", 6);
	return (0);
}
