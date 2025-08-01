/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:27:25 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/01 14:53:49 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_map game)
{
    printf("key: %d\n", keycode);
    if(keycode == ESC)
        exit(0);
    //if(keycode == )
    (void)game;
    return(0);
}

int mouse_hook(int mouse, t_map game)
{
    printf("mouse: %d", mouse);
    (void)game;
    return(0);
}

// void do_things(t_map game, int mouse, int keycode)
// {
//     int key;

//     key = mlx_key_hook(game.mlx_wind, key_hook, &game);
//     if (key == W)
        
// }