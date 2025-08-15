/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:15:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 20:29:09 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *game)
{
	game->exit_reachable = 0;
	game->collected_coin_c = 0;
	game->collected_coin = 0;
	floodfill(game, game->player_y, game->player_x);
	if (!game->exit_reachable || game->collected_coin_c != game->coin)
		ft_err(5, game);
}

void	undo_transformation(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '.')
				game->map[i][j] = '0';
			else if (game->map[i][j] == ',')
				game->map[i][j] = 'E';
			else if (game->map[i][j] == 'c')
				game->map[i][j] = 'C';
			else if (game->map[i][j] == 'p')
				game->map[i][j] = 'P';
			j++;
		}
		i++;
	}
}

void	check_vertical_borders(t_map *game, int i)
{
	if (!game->map[i])
		return ;
	if (game->map[i][0] != '1' || game->map[i][game->map_w - 1] != '1')
		ft_err(3, game);
	check_vertical_borders(game, i + 1);
}

void	has_new_line(char **map, t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '\n')
				ft_err(3, game);
			j++;
		}
		i++;
	}
}
