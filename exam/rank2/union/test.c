#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int args, char **argc)
{
	int i;
	int j;

	if (args == 3)
	{
		// 첫번째 문자열 중복 제거 출력
		i = 0;
		while (argc[1][i])
		{
			j = 0;
			// 첫번째 문자열끼리 비교
			while (j < i)
			{
				if (argc[1][i] == argc[1][j])
					break;
				j++;
			}
			if (i == j)
				ft_putchar(argc[1][i]);
			i++;
		}

		// 두번째 문자열 중복 제거 출력
		i = 0;
		while (argc[2][i])
		{
			// 첫번째 vs 두번째 비교
			j = 0;
			while (argc[1][j])
			{
				if (argc[1][j] == argc[2][i])
					break;
				j++;
			}
			// 같은 문자 존재하면 그냥 컨티뉴함
			if (argc[1][j] != '\0')
			{
				i++;
				continue;
			}
			// 두번째 문자열 끼리 비교
			j = 0;
			while (j < i)
			{
				if (argc[2][i] == argc[2][j])
					break;
				j++;
			}
			if (i == j)
				ft_putchar(argc[2][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
