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
			num = '0' + ans[i][j]; //1을 그래도 출력하면 아스키 코드값으로 그대로 49출력되므로 -48(아스키 코드로 0)해줘서 1이 그대로 출력될 수 있게 
			write(1, &num, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	trgt[3][4] = 1; // 답이 프린트 되면 플래그를 1로 켜고 
}

void	dfs(int idx1, int idx2, int ans[4][4], int trgt[4][5])
{
	int	i;

	i = 0;
	while (++i <= 4)
	{
		ans[idx1][idx2] = i;
		if (trgt[3][4]) //1이 되면 답을 이미 찾은 것 이므로 종료!!?
			return ;
		if (check_cross(idx1, idx2, ans)) //십자기 검사 먼저 진행 
		{
			check(idx1, idx2, ans, trgt); //상하좌우 보여야 하는 건물 높이 검사 
		}
	}
	ans[idx1][idx2] = -1; // 조건 불만족시 재귀함수 그전 단계로 돌아감 
}

void	check(int idx1, int idx2, int ans[4][4], int trgt[4][5]) // 왼오 위아래, 
{
	if (idx1 < 3 && idx2 == 3) //한 행이 채워지면 
	{
		if (check_left(idx1, ans, trgt) && check_right(idx1, ans, trgt))
			dfs(idx1 + 1, 0, ans, trgt); // 다음행으로 이동!
	}
	else if (idx1 == 3 && idx2 <= 3) //한 열이 다 채워지게 되면 //3행 3열 다 채우면 상하좌우 모두 검사함 
	{
		if (check_up(idx2, ans, trgt) && check_down(idx2, ans, trgt))
		{
			if (idx1 == 3 && idx2 == 3) //마지막열행
			{
				if (check_left(3, ans, trgt) && check_right(3, ans, trgt))//좌 우 포함 // 상하도 검사
				{
					print_building(ans, trgt);// 정답일시 프린트
					return ;
				}	
			}
			dfs(idx1, idx2 + 1, ans, trgt); // 다음 열로 넘어감!
		}
	}
	else if (idx1 < 3 && idx2 < 3) // 한행 한열이 다 채워지지 않았다면 
		dfs(idx1, idx2 + 1, ans, trgt); //다음 열로 넘어감 
}
