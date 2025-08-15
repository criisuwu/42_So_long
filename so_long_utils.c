/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 21:17:37 by chomobon         ###   ########.fr       */
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
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_err(2, game);
	str = ft_strdup("");
	if (!str)
	{
		close(fd);
		ft_err(1, game);
	}
	str = read_map_recursive(fd, str, game);
	close(fd);
	game->map = ft_split(str, '\n');
	free(str);
	if (!game->map[0])
		ft_err(1, game);
	return (game->map);
}

char	*read_map_recursive(int fd, char *str, t_map *game)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		return (str);
	temp = ft_strjoin(str, line);
	free(line);
	free(str);
	if (!temp)
	{
		close(fd);
		ft_err(1, game);
	}
	return (read_map_recursive(fd, temp, game));
}

void	free_map(t_map *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free (game->map[i]);
		i++;
	}
	free (game->map);
}
