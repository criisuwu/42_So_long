/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:13:37 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 21:06:47 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_err_arg(void)
{
	ft_putendl_fd("ARG ERROR", 2);
	exit(EXIT_FAILURE);
}

void	ft_err(int option, t_map *game)
{	
	free_game_resources(game);
	if (option == 1)
		ft_putendl_fd("CAN'T READ MAP ERROR", 2);
	else if (option == 2)
		ft_putendl_fd("OPEN FILE ERROR", 2);
	else if (option == 3)
		ft_putendl_fd("MAP ERROR", 2);
	else if (option == 4)
		ft_putendl_fd("OBJECTS ERROR", 2);
	else if (option == 5)
		ft_putendl_fd("CAN'T REACH EXIT", 2);
	else if (option == 6)
		ft_putendl_fd("WRONG EXTENSION", 2);
	else if (option == 7)
		ft_putendl_fd("EMPTY MAP", 2);
	else if (option == 8)
		ft_putendl_fd("CAN'T OPEN IMAGE", 2);
	exit(EXIT_FAILURE);
}

void	free_game_resources(t_map *game)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->coin_img)
		mlx_destroy_image(game->mlx, game->coin_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->mlx_wind)
		mlx_destroy_window(game->mlx, game->mlx_wind);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
}
