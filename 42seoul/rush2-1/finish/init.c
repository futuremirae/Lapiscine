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
int	ft_count_num(int argc, char *str, int num) //인자의 갯수, "입력받은 문자열", num = 0
{
	int				idx; //인덱스를 카운팅
	unsigned char	spc; //공백이면 1 => spc가 1이라면 뒤에 숫자가 온다, 띄어쓰기를 구분자로 사용!!
	char			tmp; // 각 배열에 저장된 값을 저장

	spc = 1;
	idx = -1;
	while (str[++idx] != 0)
	{
		tmp = str[idx]; // 80자 안넘기고 하려고 
		if (tmp > '0' && tmp <= '4' && spc) //1-4가 입력되었고 spc가 1이라는 건 앞에 공백이라는 것 
		{
			num++;
			spc = 0; 
		}
		else if ((tmp == ' ' || (tmp >= 9 && tmp <= 13)) && !spc) // 아스키 코드로 9-13까지는 공백을 표시! , !spc !0=>1이다
			spc = 1;
		else
			return (0);
	}
	if (spc || argc != 2 || num % 4 != 0 || num / 4 != 4)  //공백으로 끝나거나 들어온 인자가 2개가 아니거나, num이 4의 배수가 아니거나 ,num이 16이 아니면 리턴 0
		return (0);
	else
		return (num); //입력된 숫자 16 반환 
}

void	ft_init_array(int trgt[4][5], int ans[4][4], char *data) //선언한 배열을 초기화해줌. trgt는 문제지! ans 답안지
{
	int	idx_x;
	int	idx_y;

	idx_x = 0;
	while (idx_x < 4)
	{
		idx_y = 0;
		while (idx_y < 4)
		{
			trgt[idx_x][idx_y] = data[idx_x * 8 + idx_y * 2] - 48; //처음에 입력받은 문자열을 저장하게 되는데 -> 한줄로 데이터가 저장되기 때문에
			ans[idx_x][idx_y] = -1; // 우리가 프린트 해야할 답지 배열 // 확실하게 겹치지 않게 하기 위해서 
			idx_y++;
		}
		idx_x++;
	}
	trgt[3][4] = 0; //플래그 저장 인자 갯수 부족! , 답을 찾으면 출력후 플래그를 1로 바꾼다 그럼 재귀함수가 종료됨
}
