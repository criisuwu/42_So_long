/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:49:10 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/05 22:07:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_wall(t_map game)
{
    int i;
    int j;

    i = 0;
    game.wall_img = mlx_xpm_file_to_image(game.mlx, WALL, &game.wall_w, &game.wall_h);
    while(game.map[i])
    {
        j = 0;
        while(game.map[i][j])
        {
            if (game.map[i][j] == '1')
                mlx_put_image_to_window(game.mlx, game.mlx_wind, game.wall_img,
                    j * 56, i * 56);
            j++;
        }
        i++;
    }
}

void put_floor(t_map game)
{
    int i;
    int j;

    i = 0;
    game.floor = mlx_xpm_file_to_image(game.mlx, FLOOR, &game.floor_w, &game.floor_h);
    while(game.map[i])
    {
        j = 0;
        while(game.map[i][j])
        {
            if (game.map[i][j] == '0')
                mlx_put_image_to_window(game.mlx, game.mlx_wind, game.floor,
                    j * 56, i * 56);
            j++;
        }
        i++;
    }
}

void put_exit(t_map game)
{
    int i;
    int j;

    i = 0;
    game.exit_img = mlx_xpm_file_to_image(game.mlx, EXIT, &game.exit_w, &game.exit_h);
    while(game.map[i])
    {
        j = 0;
        while(game.map[i][j])
        {
            if (game.map[i][j] == 'E')
                mlx_put_image_to_window(game.mlx, game.mlx_wind, game.exit_img,
                    j * 56, i * 56);
            j++;
        }
        i++;
    }
}

void put_player(t_map game)
{
    int i;
    int j;

    i = 0;
    game.player_img = mlx_xpm_file_to_image(game.mlx, PLAYER, &game.player_w, &game.player_h);
    while(game.map[i])
    {
        j = 0;
        while(game.map[i][j])
        {
            if (game.map[i][j] == 'P')
                mlx_put_image_to_window(game.mlx, game.mlx_wind, game.player_img,
                    j * 56, i * 56);
            j++;
        }
        i++;
    }
}

void put_coin(t_map game)
{
    int i;
    int j;

    i = 0;
    game.coin_img = mlx_xpm_file_to_image(game.mlx, COIN, &game.coin_w, &game.coin_h);
    while(game.map[i])
    {
        j = 0;
        while(game.map[i][j])
        {
            if (game.map[i][j] == 'C')
                mlx_put_image_to_window(game.mlx, game.mlx_wind, game.coin_img,
                    j * 56, i * 56);
            j++;
        }
        i++;
    }
}
