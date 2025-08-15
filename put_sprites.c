/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:49:10 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 17:37:23 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->wall_w, &game->wall_h);
	if (!game->wall_img)
		ft_err(8, game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_wind,
					game->wall_img, j * 56, i * 56);
			j++;
		}
		i++;
	}
}

void	put_floor(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR,
			&game->floor_w, &game->floor_h);
	if (!game->floor)
		ft_err(8, game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_wind, game->floor,
					j * 56, i * 56);
			j++;
		}
		i++;
	}
}

void	put_exit(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &game->exit_w,
			&game->exit_h);
	if (!game->exit_img)
		ft_err(8, game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_wind,
					game->exit_img, j * 56, i * 56);
			j++;
		}
		i++;
	}
}

void	put_player(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER, &game->player_w,
			&game->player_h);
	if (!game->player_h)
		ft_err(8, game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_wind,
					game->player_img, j * 56, i * 56);
			j++;
		}
		i++;
	}
}

void	put_coin(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->coin_img)
		mlx_destroy_image(game->mlx, game->coin_img);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, COIN,
			&game->coin_w, &game->coin_h);
	if (!game->coin_img)
		ft_err(8, game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_wind,
					game->coin_img, j * 56, i * 56);
			j++;
		}
		i++;
	}
}
