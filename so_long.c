/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:35:46 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/28 12:40:21 by chomobon         ###   ########.fr       */
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
