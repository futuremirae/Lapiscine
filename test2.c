#include <stdlib.h>

int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int total_len(char **strs, char *sep, int size)
{
	int i;
	int lenth;

	i = 0;
	lenth = str_len(sep) * (size - 1);
	while (i < size)
	{
		lenth += str_len(str[i]);
		i++;
	}
	return (lenth);
}

char *ft_strcat(char *result, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (result[i])
		i++;
	while (src[j])
	{
		result[i] = src[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}
char *ft_strjoin(int size, char **strs, char *sep)
{
	char *result;
	int total_len;
	int i;

	i = 0;
	total_len = total_len(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_len+1));
	if (!result)
		return (0);
	result[0] = 0;
	if (size == 0)
		return (result);
	while (i < size - 1)
	{
		ft_strcat(result, strs[i]);
		ft_strcat(result, sep);
		i++;
	}
	ft_strcat(result, strs[i]);
	result[total_len] = 0;
	return (result);
}

	











