/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/01 14:06:34 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    char *temp;
    int fd;

    str = ft_strdup("");
    if (!str)
        ft_err(1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        free(str);
        ft_err(2);
    }
    while ((line_map = get_next_line(fd)) != NULL)
    {
        temp = str;
        str = ft_strjoin(str, line_map);
        free(temp);
        free(line_map);
        if (!str)
        {
            close(fd);
            ft_err(1);
        }
    }
    close(fd);
    game.map = ft_split(str, '\n');
    free(str);
    if (!game.map)
        ft_err(1); 
    return (game.map);
}
