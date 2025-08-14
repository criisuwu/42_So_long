/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:15:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 19:08:49 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map(t_map *game)
{
    game->exit_reachable = 0;
    game->collected_coin_c = 0;
    game->collected_coin = 0;
    floodfill(game, game->player_y, game->player_x);
    if (!game->exit_reachable || game->collected_coin_c != game->coin)
        ft_err(5, game);
}
void undo_transformation(t_map *game)
{
    int i;
    int j;

    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == '.')
                game->map[i][j] = '0';
            else if(game->map[i][j] == ',')
                game->map[i][j] = 'E';
            else if (game->map[i][j] == 'c')
                game->map[i][j] = 'C';
            else if (game->map[i][j] == 'p')
                game->map[i][j] = 'P';
            j++;
        }
        i++;
    }
}
