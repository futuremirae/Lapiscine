/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                           :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyeuk <dongyeuk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:47:16 by dongyeuk          #+#    #+#             */
/*   Updated: 2023/07/30 15:58:02 by dongyeuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	dfs(int idx1, int idx2, int ans[4][4], int trgt[4][5]);
int		ft_count_num(int argc, char *str, int num);
void	ft_init_array(int trgt[4][5], int ans[4][4], char *data);

int	main(int argc, char *args[]) // 배열에 저장된 값에 접근하기 위해서 
{
	int			trgt[4][5];
	int			ans[4][4];
	const int	num = ft_count_num(argc, args[argc - 1], 0) / 4; // const는 상수 선언으로 값이 절대 바뀌지 않음!

	if (num == 4) 
	{
		ft_init_array(trgt, ans, args[1]); // 선언한 배열을 초기화해주고 , 만약 인자를 2개로 (실행파일과 "입력할 문자열")-> 마지막에 들어온 문자열을 의미!
	}
	if (num != 4) //앞에서 이미 16아니면 거르지 않나요???
	{
		write(1, "Error\n", 6);
		return (0);
	}
	dfs(0, 0, ans, trgt); //전역변수를 사용할 수 없기때문에 포인터처럼 인자로 값을 넣어줘야 바뀐 값이 저장됨
	if (!trgt[3][4]) //?????
		write(1, "Error\n", 6);
	return (0);
}
