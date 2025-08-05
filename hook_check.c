/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:27:25 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/05 17:14:01 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_map *game)
{
    if(keycode == ESC)
        exit(0);
    else if (keycode == W)
        move_player(game, game->player_x, game->player_y);
    else if (keycode == S)
        move_player(game, game->player_x, game->player_y);
    else if (keycode == A)
        move_player(game, game->player_x, game->player_y);
    else if (keycode == D)
        move_player(game, game->player_x, game->player_y);
    return(0);
}
