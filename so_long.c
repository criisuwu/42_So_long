/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:35:46 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/28 17:17:59 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Esta funcion libera todo el mapa, primero el contenido y finalmente libera
//el puntero
void    free_map(t_map *map)
{
    int i;

    i = 0;
    if (map->map)
    {
        while (map->map[i])
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
    }
}

//Con esta funcion inicializo las varibles a 0
void    set_variables(t_map *map)
{
    map->coin = 0;
    map->exit = 0;
    map->n_players = 0;
    map->movements = 0;
}

//Esta funcion situa la salida(una vez recogido los coleccionables)
void    set_exit(int col, int row, t_map *map)
{
    map->exit_x = row;
    map->exit_y = col;
    map->exit++;
}

void    set_map(t_map *map)
{
    map->mlx = mlx_init(map->map_wid * 56, map->map_hei * 56, "SO_LONG", true);
    
}