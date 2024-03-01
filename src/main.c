/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edamar <edamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:54:36 by edamar            #+#    #+#             */
/*   Updated: 2024/02/29 17:06:31 by edamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/structs.h"
#include "../Libft/libft.h"
#include "../Libft/get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int all_game_init(t_game *game, char *av);

int	extension(char *extension) // DÜZENLENİCEK!!
{
	int	i;

	i = ft_strlen (extension);
	if (i < 4)
		return (0);
	return (1);
	
}

//gcc main.c map_check.c ../Libft/ft_strlen.c ../Libft/ft_substr.c ../Libft/ft_split.c ../Libft/ft_strlcpy.c ../Libft/ft_strdup.c ../get_next_line/get_next_line.h ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (extension (av[1]) == 0)
			return (printf ("please enter the correct argument\n<name>.cub\n"), 0);
		if (all_game_init (&game, av[1]) == 0)
			return (1);
		//start_game()
	}
	else
	{
		printf ("missing argument\n");
		return (1);
	}
	return (0);
}
