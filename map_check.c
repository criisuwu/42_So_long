/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:48:32 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/24 17:42:03 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void is_rectangle(t_map game)
{
    if (game.map_h == game.map_w || game.map_h > game.map_w)
        ft_err();
}

void map_is_valid(t_map game)
{
    int i;
    
    i = 0;
    while (game.map[i])
    {
        if (game.map[i][0] != '1' || game.map[i][game.map_w - 1] != '1')
            ft_err();
        else
            i++;
    }i = 0;
    while (game.map[0][i])
    {
        if (game.map[0][i] == '1')
            i++;
        else if(game.map[0][i] != '1')
            ft_err();
    }
    i = 0;
    while (game.map[game.map_h - 1][i])
    {
        if (game.map[game.map_h - 1][i] == '1')
            i++;
        else if(game.map[game.map_h - 1][i] != '1')
            ft_err();
    }
}

