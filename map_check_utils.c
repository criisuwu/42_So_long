/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:15:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/12 16:03:25 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map(t_map *game)
{
    game->exit_reachable = 0;
    game->collected_coin_c = 0;
    floodfill(game, game->player_y, game->player_x);
    if (!game->exit_reachable || game->collected_coin_c != game->coin)
    {
        printf("Error: El mapa no es completable\n");
        printf(" - Salida accesible: %s\n", game->exit_reachable ? "Sí" : "No");
        printf(" - Coins recolectados: %d/%d\n", game->collected_coin_c, game->coin);
        ft_err(5);
    }
}