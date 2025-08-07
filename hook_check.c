/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:27:25 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/07 23:03:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_map *game)
{
    if(keycode == ESC)
        exit(0);
    else if (keycode == W)
    {
        clean_wind(game);
        move_player(game, game->player_x, game->player_y - 1);
    }
    else if (keycode == S)
    {
        move_player(game, game->player_x, game->player_y + 1);
        clean_wind(game);
    }
    else if (keycode == A)
    {
        move_player(game, game->player_x - 1, game->player_y);
        clean_wind(game);
    }
    else if (keycode == D)
    {
        move_player(game, game->player_x + 1, game->player_y);
        clean_wind(game);
    }
    return(0);
}

void clean_wind(t_map *game)
{
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->floor)
        mlx_destroy_image(game->mlx, game->floor);
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);
    if (game->coin_img)
        mlx_destroy_image(game->mlx, game->coin_img);
}