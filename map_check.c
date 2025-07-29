/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:48:32 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/29 14:25:07 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_is_valid(t_map game)
{
    int i;
    
    i = 0;
    while (game.map[i])
    {
        if (game.map[i][0] != '1' || game.map[i][game.map_w - 1] != '1')
            ft_err(3);
        else
            i++;
    }i = 0;
    while (game.map[0][i])
    {
        if (game.map[0][i] == '1')
            i++;
        else if(game.map[0][i] != '1')
            ft_err(3);
    }
    i = 0;
    while (game.map[game.map_h - 1][i])
    {
        if (game.map[game.map_h - 1][i] == '1')
            i++;
        else if(game.map[game.map_h - 1][i] != '1')
            ft_err(3);
    }
}

void has_one_player(t_map game)
{
    int count_p;
    int i;
    int j;

    count_p = 0;
    i = 1;
    j = 0;
    while (game.map[i][j])
    {
        while(game.map[i][j])
        {
            if(game.map[i][j] == 'P')
                count_p++;
            j++;
        }
        i++;
    }
    if(count_p != 1)
        ft_err(4);
}

void has_one_exit(t_map game)
{
    int count_exit;
    int i;
    int j;

    count_exit = 0;
    i = 1;
    j = 0;
    while (game.map[i][j])
    {
        while(game.map[i][j])
        {
            if (game.map[i][j] == 'E')
                count_exit++;
            j++;
        }
        i++;
    }
    if (count_exit != 1)
        ft_err(4);
}

void has_collec(t_map game)
{
    int count_c;
    int i;
    int j;

    count_c = 0;
    i = 1;
    j = 0;
    while (game.map[i][j])
    {
        while(game.map[i][j])
        {
            if (game.map[i][j] == 'C')
                count_c++;
            j++;
        }
        i++;
    }
    printf("%d\n", count_c);
    if (count_c < 1)
        ft_err(4);
}
