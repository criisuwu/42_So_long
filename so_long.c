/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:27:21 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/11 16:30:48 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_map game;

    if (argc < 2)
        ft_err();
    (void) argv;
    game.mlx = mlx_init();
    game.mlx_wind = mlx_new_window(game.mlx, 1 * 56, 1 * 56, "So_Long");
    return (0);
}