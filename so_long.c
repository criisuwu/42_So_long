/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:27:21 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/24 17:22:52 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_map game;

    (void) argv;
    if (argc != 2)
        ft_err();
    game.mlx = mlx_init();
    game.map = read_map(argv, game);
    game.map_w = get_map_width(game);
    game.map_h = get_map_height(game);
    is_rectangle(game);
    map_is_valid(game);
    game.mlx_wind = mlx_new_window(game.mlx, game.map_w * 56, game.map_h * 56, "So_Long");
    mlx_key_hook(game.mlx_wind, key_hook, &game);
    mlx_loop(game.mlx);
    return (0);
}
