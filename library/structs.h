/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edamar <edamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:04:49 by edamar            #+#    #+#             */
/*   Updated: 2024/02/29 13:59:10 by edamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_img
{
	void	*image;
	int	height;
	int	width;
}	t_img;


typedef struct s_player
{
	double	x;
	double	y;
}	t_player;

typedef struct s_map
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	int	ceiling; 
	int	floor; 
	char	**map;
}	t_map;

typedef struct s_game
{
	t_player	player;
	t_map		map;
}	t_game;

int	init_image(t_map *map, char **matrix);

#endif