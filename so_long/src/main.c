/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:36:46 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/02 20:36:47 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_arg(int args, char **argc)
{
	char	*extension;

	if (args != 2)
		return (1);
	extension = ft_strrchr(argc[1], '.');
	if (extension == 0)
		return (1);
	if (ft_strlen(extension) != 4)
		return (1);
	if (ft_strncmp(extension, ".ber", 4) != 0)
		return (1);
	return (0);
}

int	main(int args, char **argc)
{
	/*
	argc check : check_arg 
		1. 명령행 인자 개수 확인
		2. 파일의 확장자 검사
	*/
	if (check_arg(args, argc))
		error_message();
	/*
	argc map 구조체로 변환 : convert_arg 
		1. map 구조체 구현
			map 요소 : 전체 맵 크기 (x, y 크기)
					  벽의 위치 (x, y 좌표)
					  캐릭터의 위치 (x, y 좌표)
					  아이템의 위치 (x, y 좌표)
					  아이템의 획득 여부 (true/false)
					  출구의 위치 (x, y 좌표)
		2. 각 map 정보를 gnl로 받아 구조체 속성 삽입
	*/
	/*
	map 검사 : check_map 
		1. map이 직사각형인지 검사
		2. 각 P는 무조건 하나 C E 0 1 최소한 하나 있는지 검사
		3. 벽 테두리가 잘 있는지 검사
		3. 1 0 P C E가 아닌 값이 들어왔는지 검사
	*/

	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_loop(mlx_ptr);
}
