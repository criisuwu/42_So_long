/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:59:17 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/26 16:15:03 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Esto pone la imagen en el mapa y abre la ventana
void    draw_floor(t_map *map)
{
    int col;
    int row;

    col = 0;
    while (map->map[col])
    {
        row = 0;
        while (map->map[col][row])
        {
            mlx_image_to_window(map->mlx, map->floor, row * 56, col * 56);
            row++;
        }
        col++;
    }
}

//Esto pondra las imagenes en cada objeto
void    draw_element(int col, int row, t_map *map)
{
    if (map->map[col][row] == '1')
        mlx_image_to_window(map->mlx, map->wall_img, row * 56, col * 56);
    if (map->map[col][row] == 'P')
        mlx_image_to_window(map->mlx, map->player_img, row * 56, col * 56);
    if (map->map[col][row] == 'C')
        mlx_image_to_window(map->mlx, map->coin_img, row * 56, col * 56);
    if (map->map[col][row] == 'E')
        mlx_image_to_window(map->mlx, map->exit_img, row * 56, col * 56);
}

//Esto genera el mapa para el videojuego
void    draw_map(t_map *map)
{
    int col;
    int row;

    col = 0;
    draw_floor(map);
    while (map->map[col])
    {
        row = 0;
        while (map->map[col][row])
        {
            draw_element(col, row, map);
            row++;
        }
        col++;
    }
}