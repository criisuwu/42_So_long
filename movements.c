/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:55:13 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/05 20:32:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_position(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < (int)game->map_h)
	{
		x = 0;
		while (x < (int)game->map_w)
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
			exit(0);
		}
        if (game->map[new_y][new_x] == 'C')
			game->collected_coin++;
        if(game->map[new_y][new_x] == 'C' || game->map[new_y][new_x] == '0')
        {
            game->map[game->player_x][game->player_y] = '0';
            game->player_x = new_x;
            game->player_y = new_y;
            game->map[new_y][new_x] = 'P';
            game->mvs++;
            redraw_map(game);
        }
    }
}

void redraw_map(t_map *game)
{
    int i;
    int j;

    i = 0;
    mlx_clear_window(game->mlx, game->mlx_wind);
    while(i < (int)game->map_h)
    {
        j = 0;
        while(j < (int)game->map_w)
        {
            put_coin(*game);
            put_exit(*game);
            put_floor(*game);
            put_player(*game);
            put_wall(*game);
            j++;
        }
        i++;
    }
}