/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:43:16 by marvin            #+#    #+#             */
/*   Updated: 2025/08/13 22:43:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void keep_exit(t_map *game, int x, int y)
{
	game->map[game->exit_y][game->exit_x] = 'E';
    game->exit_x = x;
    game->exit_y = y;
    game->map[y][x] = 'P';
    drawmap(game);
}

void change_player_pos(t_map *game, int x, int y)
{
    game->map[game->player_y][game->player_x] = '0';
    game->player_x = x;
    game->player_y = y;
    game->map[y][x] = 'P';
    game->mvs++;
    drawmap(game);
}