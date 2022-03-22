#include <unistd.h>

void	print_arr(char arr[4][4])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, &arr[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}

char	*set_check_arr(char arr[4][4], char *check_arr, int check_idx, int size)
{
	int	direct;
	int	i;
	int idx;

	direct = size * 2;
	i = 0;
	idx = check_idx;
	while (i < size)
	{
		if (check_idx <= direct - 2)
			check_arr[i] = arr[i][check_idx / 2];
		else if (check_idx > direct - 2 && check_idx <= (direct * 2) - 2)
			check_arr[i] = arr[size - 1 - i][(check_idx - 8) / 2];
		else if (check_idx > (direct * 2) - 2 && check_idx <= (direct * 3) - 2)
			check_arr[i] = arr[(check_idx - 16) / 2][i];
		else if (check_idx > (direct * 3) - 2 && check_idx <= (direct * 4) - 2)
			check_arr[i] = arr[(check_idx - 24) / 2][size - 1 - i];
		i++;
	}
	return (check_arr);
}

int	check_value(char check, char *arr, int size)
{
	int		i;
	int		count;
	char	max;

	i = 1;
	count = 0;
	max = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			count++;
		}
		i++;
	}
	if (count == (check - 1) - '0')
		return (1);
	return (0);
}

void	set_arr(char dest[4], char src[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
}

int check_side(char arr[4][4], char *check, int row)
{
	int		flag;
	char	check_arr[4];
	int		i;
	int		j;

	i = 0;
	j = 2;
	flag = 0;
	while (i < 4)
		check_arr[i++] = '0';
	while (j < 4)
	{
		set_check_arr(arr, check_arr, (row * 2) + (8 * j), 4);
		flag += check_value(check[(row * 2) + (8 * j)], check_arr, 4);
		j++;
	}
	if (flag == 2)
		return (1);
	return (0);
}

int	is_duplicate(char *arr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i != j && arr[i] == arr[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_all(char arr[4][4], char *check)
{
	int		flag;
	char	check_arr[4];
	int 	i;
	int		j;

	flag = 0;
	i = 0;
	j = 0;
	while (i < 4)
		check_arr[i++] = '0';
	while (j <= 30)
	{
		set_check_arr(arr, check_arr, j, 4);
		if (is_duplicate(check_arr))
			return (0);
		flag += check_value(check[j], check_arr, 4);
		j += 2;
	}
	if (flag == 16)
		return (1);
	return (0);
}

int	is_possible(char arr[4][4], char *check, int row)
{
	int	flag;
	int	i;
	char	check_arr[4];

	i = 0;
	flag = 0;
	while(i < 4)
		check_arr[i++] = '0';
	if (row < 4)
	{
		if (check_side(arr, check, row))
			return (1);
	}
	return (0);
}

void	rush01(char arr[4][4], char num[24][4], int row, char *check )
{
	int	i;

	i = 0;
	if (row == 4)
	{
		if (check_all(arr, check))
			print_arr(arr);
		return ;
	}
	else
	{
		while (i < 24)
		{
			set_arr(arr[row], num[i]);
			if (is_possible(arr, check, row))
			{
				rush01(arr, num, row + 1, check);
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	char arr2[4][4] = {
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'},
		{'0','0','0','0'} };

	char check_arr[24][4] = {
		{'1','2','3','4'}, {'1','2','4','3'}, {'1','3','2','4'}, {'1','3','4','2'}, 
		{'1','4','2','3'}, {'1','4','3','2'},{'2','1','3','4'}, {'2','1','4','3'},
		{'2','3','1','4'}, {'2','3','4','1'},{'2','4','1','3'}, {'2','4','3','1'},
		{'3','1','2','4'}, {'3','1','4','2'},{'3','2','1','4'}, {'3','2','4','1'},
		{'3','4','1','2'}, {'3','4','2','1'},{'4','1','2','3'}, {'4','1','3','2'},
		{'4','2','1','3'}, {'4','2','3','1'},{'4','3','1','2'}, {'4','3','2','1'}};

	char *check = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	rush01(arr2, check_arr, 0, av[1]);
}
