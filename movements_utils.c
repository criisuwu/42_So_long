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
    int old_x;
    int old_y;
    old_x = game->player_x;
    old_y = game->player_y;
    game->map[old_y][old_x] = '0';
    game->player_x = x;
    game->player_y = y;
    game->map[y][x] = 'P';
    drawmap(game);
}

void change_player_pos(t_map *game, int x, int y)
{
    if ((game->player_y == game->exit_y) && (game->player_x == game->exit_x))
        game->map[game->player_y][game->player_x] = 'E';
    else
        game->map[game->player_y][game->player_x] = '0';
    game->player_x = x;
    game->player_y = y;
    game->map[y][x] = 'P';
    game->mvs++;
    drawmap(game);
}
