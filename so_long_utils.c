/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/24 17:06:13 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_err()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

int get_map_width(t_map game)
{
    game.map_w = ft_strlen(game.map[0]);
    return (game.map_w);
}

int get_map_height(t_map game)
{
    int i;

    i = 0;
    while (game.map[i])
    {
        i++;
    }
    return (i);
}

char **read_map(char **argv, t_map game)
{
    char *line_map;
    char *str;
    int fd;

    str = ft_strdup("");
    if (!str)
        ft_err();
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        free(str);
        ft_err();
    }
    while ((line_map = get_next_line(fd)) != NULL)
    {
        str = ft_strjoin(str, line_map);
    }
    close(fd);
    game.map = ft_split(str, '\n');
    free(str);
    return (game.map);
}
