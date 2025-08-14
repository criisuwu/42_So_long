/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:55:13 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 20:47:19 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_position(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_err(4, game);
}

int	not_wall(t_map *game, int x, int y)
{
	char	tile;

	if ((x >= 0 && x < (int)game->map_w) && (y >= 0 && y < (int)game->map_h))
	{
		tile = game->map[y][x];
		return (tile == '0' || tile == 'C' || tile == 'E');
	}
	return (0);
}

void	init_exit(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_err(4, game);
}

void	move_player(t_map *game, int new_x, int new_y)
{
	int	tile;

	tile = not_wall(game, new_x, new_y);
	if (tile)
	{
		if (game->map[new_y][new_x] == 'E'
		&& (game->collected_coin == game->coin))
		{
			ft_printf("You won! Total movements: %d\n", game->mvs);
			free_game_resources(game);
			exit(0);
		}
		if (game->map[new_y][new_x] == 'C')
			game->collected_coin++;
		if (game->map[new_y][new_x] == 'C'
			|| game->map[new_y][new_x] == '0')
		{
			change_player_pos(game, new_x, new_y);
		}
		if (game->map[new_y][new_x] == 'E')
			keep_exit(game, new_x, new_y);
	}
}
