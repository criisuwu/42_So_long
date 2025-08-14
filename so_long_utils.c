/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 18:09:05 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(t_map *game)
{
	game->map_w = ft_strlen(game->map[0]);
	return (game->map_w);
}

int	get_map_height(t_map *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		i++;
	}
	return (i);
}

char	**read_map(char **argv, t_map *game)
{
	char	*line_map;
	char	*str;
	char	*temp;
	int		fd;

	str = ft_strdup("");
	if (!str)
		ft_err(1, game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(str);
		ft_err(2, game);
	}
	while ((line_map = get_next_line(fd)) != NULL)
	{
		temp = ft_strjoin(str, line_map);
		free(line_map);
		if (!str)
		{
			close(fd);
			ft_err(1, game);
		}
		free(str);
		str = temp;
	}
	close(fd);
	game->map = ft_split(str, '\n');
	if (!game->map)
	{
		free(str);
		ft_err(1, game);
	}
	return (free(str), game->map);
}

void	free_map(t_map *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free (game->map[i]);
		i++;
	}
	free (game->map);
}
