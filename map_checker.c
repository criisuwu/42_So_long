/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:22:56 by chomobon          #+#    #+#             */
/*   Updated: 2024/09/04 13:56:42 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Esta funcion verifica que el mapa esta hecho de elementos validos y que
//contenga todos los necesarios
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
                ft_error(4, map);
            row++;
        }
        col++;
    }
    return(1);
}

//Verifica que el mapa sea rectangular, en caso negativo da un error
void rect_check(t_map *map)
{
    size_t  col;
    
    col = 0;
    map->map_wid = 0;
    map->map_hei = ft_strlen(map->map[col]);
    while (map->map[col])
    {
        map->map_wid++;
        col++;
    }
    col = 0;
    while (map->map_wid > col)
    {
        if (map->map_hei != ft_strlen(map->map[col]))
            ft_error(4, map);
        col++;
    }
}

void    count_elements(t_map  *map)
{
    int col;
    int row;

    col = -1;
    while (map->map[++col])
    {
        row = 1;
        while (map->map[col][++row])
        {
            if (map->map[col][row] == 'C')
                map->coin++;
            else if (map->map[col][row] == 'E')
                set_exit(col, row, map);
            else if (map->map[col][row] == 'P')
            {
                map->player_y = col;
                map->player_x = row;
                map->n_players++;
            }
        }
    }
    check_element_num(map);
}

int check_border(t_map *map)
{
    int col;
    int row;

    col = 0;
    while (map->map[col])
    {
        row = 0;
        while (map->map[col][row])
        {
            if (map->map[0][row] != '1'
                || map->map[col][0] != '1'
                || map->map[map->map_wid - 1][row] != '1'
                || map->map[col][map->map_hei - 1] != '1')
                ft_error(5, map);
            row++;
        }
        col++;
    }
    return (1);
}

void    check_element_num(t_map *map)
{
    map->coin_cop = map->coin;
    map->coin_cop_2 = map->coin;
    map->player_copy = map->player_copy;
    if (map->coin < 1 || map->exit != 1 || map->n_players != 1)
        ft_error(6, map);
}