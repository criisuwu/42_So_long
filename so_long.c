/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:27:21 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/14 14:00:29 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_map game;

    (void) argv;
    if (argc < 2)
        ft_err();
    game.mlx = mlx_init();
    game.map_w = get_map_width(argv);
    game.map_h = get_map_height(argv);
    game.mlx_wind = mlx_new_window(game.mlx, game.map_w * 56, game.map_h * 56, "So_Long");
    mlx_loop(game.mlx);
    return (0);
}