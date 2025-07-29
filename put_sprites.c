/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:49:10 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/29 15:05:20 by chomobon         ###   ########.fr       */
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
