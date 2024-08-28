/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:22:56 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/26 16:30:10 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_obj_map(t_map *map)
{
    char    **map_aux;
    int     col;
    int     row;

    map_aux = map->map;
    col = 0;
    while (map_aux[col])
    {
        row = 0;
        while (map_aux[col][row])
        {
            if (map_aux[col][row] != '1' && map_aux[col][row] != '0' &&
                map_aux[col][row] != 'C' && map_aux[col][row] != 'E' &&
                map_aux[col][row] != 'P')
                //error
            row++;
        }
        col++;
    }
}