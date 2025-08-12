/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:55:13 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/12 14:55:35 by chomobon         ###   ########.fr       */
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
	perror("Error: No se encontró la posición inicial del jugador.\n");
	exit(1);
}

int not_wall(t_map *game, int x, int y)
{
    char tile;
    if((x >= 0 && x < (int)game->map_w) && (y >= 0 && y < (int)game->map_h))
    {
        tile = game->map[y][x];
        return(tile == '0' || tile == 'C' || tile == 'E');
    }
    return(0);
}

void move_player(t_map *game, int new_x, int new_y)
{
    int tile;
    tile = not_wall(game, new_x, new_y);
    if(tile)
    {
        if (game->map[new_y][new_x] == 'E'
		&& (game->collected_coin == game->coin))
		{
			printf("¡Has salido! Movimientos totales: %d\n", game->mvs); //Tengo que meter el ft_printf
			clean_wind(game);
			exit(0);
		}
        if (game->map[new_y][new_x] == 'C')
			game->collected_coin++;
        if(game->map[new_y][new_x] == 'C' || game->map[new_y][new_x] == '0')
        {
            game->map[game->player_y][game->player_x] = '0';
            game->player_x = new_x;
            game->player_y = new_y;
            game->map[new_y][new_x] = 'P';
            game->mvs++;
            drawmap(game);
        }
    }
}
