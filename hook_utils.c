/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:27:25 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/12 17:05:00 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_map *game)
{
    if(keycode == ESC)
        exit(0);
    else if (keycode == W)
    {
        //clean_wind(game);
        move_player(game, game->player_x, game->player_y - 1);
    }
    else if (keycode == S)
    {
        //clean_wind(game);
        move_player(game, game->player_x, game->player_y + 1);
    }
    else if (keycode == A)
    {
        //clean_wind(game);
        move_player(game, game->player_x - 1, game->player_y);
    }
    else if (keycode == D)
    {
        //clean_wind(game);
        move_player(game, game->player_x + 1, game->player_y);
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
    game->wall_img = NULL;
    game->floor = NULL;
    game->player_img = NULL;
    game->exit_img = NULL;
    game->coin_img = NULL;
    if (game->mlx_wind)
        mlx_destroy_window(game->mlx, game->mlx_wind);
}

int close_window(t_map *game)
{
    clean_wind(game);
    exit(0);
    return (0);
}