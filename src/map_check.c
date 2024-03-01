/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edamar <edamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:48:59 by edamar            #+#    #+#             */
/*   Updated: 2024/02/29 18:18:13 by edamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/structs.h"
#include "../Libft/libft.h"
#include "../Libft/get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

void	free_matrix(char ***line);
int	matrix_len(char **matrix);

int	search_path(char **line_ct)
{
	int fd;
	printf("%s", line_ct[1]);
	fd = open (line_ct[1], O_RDONLY);
	if (fd == -1 )
		exit(1);
}

int	control_path(char **line_ct, int flag)
{
	int	search_flag;

	if (matrix_len(line_ct) != 2) // bura için bir free yapılması gerek
		return (1);
	if (search_path(line_ct))
		return (1);
	return 0;
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	init_image(t_map *map, char **matrix) // leaks problemi var
{
	char	**line_ct;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (matrix[i])
	{
		line_ct = ft_split(matrix[i], ' ');
		if ((ft_strncmp(line_ct[0], "NO", 3) == 0) && ++counter)
			control_path(line_ct, 1);
		else if (ft_strncmp(line_ct[0], "SO", 3) == 0 && ++counter)
			control_path(line_ct, 2);
		else if (ft_strncmp(line_ct[0], "WE", 3) == 0 && ++counter)
			control_path(line_ct, 3);
		else if (ft_strncmp(line_ct[0], "EA", 3) == 0 && ++counter)
			control_path(line_ct, 4);
		i++;
		free_matrix(&line_ct);
	}
	if (counter != 4)
		return (0);
	return (1);
}

void	free_matrix(char ***line) // map okumadan sonra free
{
	int	i;

	i = 0;
	if (!(*line))
		return ;
	while ((*line)[i])
	{
		free((*line)[i]);
		i++;
	}
	free ((*line));
	(*line) = NULL;
}

void	map_init(t_map *map) // map başlatırken NULL
{
	map->east.image = NULL;
	map->north.image = NULL;
	map->west.image = NULL;
	map->south.image = NULL;
	map->map = NULL;
	map->ceiling = 240;	//DEFİNE OLARAK TANIMALNICAK
	map->floor = 249;	//DEFİNE OLARAK TANIMLANICAK
}

char	**map_read(char *map)
{
	int		i;
	int		fd;
	char	**matrix;

	fd = open (map, O_RDONLY);
	if (fd == -1)
		exit (1);
	matrix = malloc (sizeof(char**) * 1024);//AÇILACAK ALAN DÜZENLENİCEK
	if (!matrix)
		exit (1);
	i = 0;
	while (1)//Tabları space çevirilicek fonksiyon yazılacak
	{
		matrix[i] = get_next_line(fd);
		if (!matrix[i])
			break;
		i++;
	}
	close (fd);
	return (matrix);
}

int	all_game_init(t_game *game, char *map)
{
	int		i;
	char	**matrix;

	matrix = map_read(map);
	map_init(&game->map);
	if (!init_image(&game->map, matrix))
		return (free_matrix(&matrix), 1);
	/* init_map(&game->map, matrix); */
	i = 0;
	while (matrix[i])
	{
		printf("%s", matrix[i]);
		i++;
	}
	free_matrix(&matrix);
	return (1);
}
