/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:27:25 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/05 19:44:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_map *game)
{
    if(keycode == ESC)
        exit(0);
    else if (keycode == W)
        move_player(game, game->player_x, game->player_y - 1);
    else if (keycode == S)
        move_player(game, game->player_x, game->player_y + 1);
    else if (keycode == A)
        move_player(game, game->player_x - 1, game->player_y);
    else if (keycode == D)
        move_player(game, game->player_x + 1, game->player_y);
    return(0);
}
