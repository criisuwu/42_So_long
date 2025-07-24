/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:48:32 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/24 16:28:26 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void is_rectangle(t_map game)
{
    if (game.map_h < game.map_w)
        ft_err();
}

void map_is_valid(t_map game)
{
    int i;
    
    i = 0;
    while (game.map[0][i])
    {
        if (game.map[0][i] == '1')
            i++;
        else if(game.map[0][1] != '1')
            ft_err();
    }
    i = 0;
    while (game.map[i])
    {
        if (game.map[i][0] != '1' || game.map[i][game.map_h])
            ft_err();
        else
            i++;
    }
}
