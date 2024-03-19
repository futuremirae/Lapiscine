int ft_atoi(char *str)
{
	int i;
	int negative;
	long long numbers;

	i = 0;
	negative = 1;
	numbers = 0;
	while ( str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numbers *= 10;
		numbers += str[i] - '0';
		i++;
	}
	return (numbers * negative);
}
int basecheck(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == 0 || base[1] == 0)
		return 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}
void basenum(long long num, int base-len, char *base)
{
	int lenth;
	int answer[32];

	lenth = 0;
	while (num > 0)
	{
		answer[lenth] = num % base_len;
		num /= base_len;
		lenth++;
	}
	while (lenth > 0)
	{
		write(1, &base[answer[lenth-1]],1);
		lenth --;
	}
}

void ft_putnbr_base(int nbr, char *base)
{
	int base_len;
	long long num;

	if (basecheck(base) == 0)
		return ;
	base_len = basecheck(base);
	num = (long long)nbr;
	if (num == 0)
	{
		write(1, &base[0],1);
		return ;
	}
	if (num < 0)
	{
		write(1, "-",1);
		num *= -1;
	}
	























