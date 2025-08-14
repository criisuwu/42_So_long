/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:27:21 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 19:31:55 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checking(t_map *game)
{
	map_is_valid(game);
	has_one_player(game);
	has_one_exit(game);
	has_collect(game);
	check_map(game);
}

void	drawmap(t_map *game)
{
	put_floor(game);
	put_wall(game);
	put_exit(game);
	put_player(game);
	put_coin(game);
}

void check_extension(char *ext)
{
	if ((ft_strncmp(ext + ft_strlen(ext) - 4, ".ber", 4)))
		exit(1);
}

int	main(int argc, char **argv)
{
	t_map	game;

	ft_bzero(&game, sizeof(t_map));
	if (argc != 2)
		ft_err_arg();
	check_extension(argv[1]);
	game.mlx = mlx_init();
	game.map = read_map(argv, &game);
	game.map_w = get_map_width(&game);
	game.map_h = get_map_height(&game);
	init_player_position(&game);
	init_exit(&game);
	map_checking(&game);

	undo_transformation(&game);
	game.mlx_wind = mlx_new_window(game.mlx, game.map_w * 56,
			game.map_h * 56, "So_Long");
	drawmap(&game);
	mlx_key_hook(game.mlx_wind, key_hook, &game);
	mlx_hook(game.mlx_wind, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
