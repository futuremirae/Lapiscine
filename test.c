#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if(s1[i] != s2[i])
			return ((unsigned char)s1[i]- (unsigned char)s2[i]);
		else
			i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void swap(int argc, char **argv)
{
	int i;
	int j;
	char *temp;

	i = 0;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1 - i)
		{
			if (ft_strcmp(argv[j], argv[j+1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j+1];
				argv[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}
int str_len(char *s1)
{
	int i;
	i = 0;
	while (s1[i])
		i++;
	return (i);
}
int main(int argc , char *argv[])
{
	int i;

	i = 1;
	swap(argc, argv);
	while (i < argc)
	{
		write(1, argv[i], str_len(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}














