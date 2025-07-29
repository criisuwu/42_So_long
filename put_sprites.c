/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:49:10 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/29 14:11:37 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_wall(t_map game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    game.wall_img = mlx_xpm_file_to_image(game.mlx, WALL, &game.wall_w, &game.wall_h);
    while(game.map[i][j])
    {
        while(game.map[i][j])
        {
            if (game.map[i][j] == '1')
                mlx_put_image_to_window(game.mlx, game.mlx_wind, game.wall_img,
                    game.wall_w, game.wall_h);
            j++;
        }
        i++;
    }
}