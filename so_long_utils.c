/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:10:45 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/14 13:59:28 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_err()
{
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}

int get_map_width(char **argv)
{
    char *line_map;
    int fd;
    int width;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_err();
    line_map = get_next_line(fd);
    if (!line_map)
    {
        close(fd);
        ft_err();
    }
    width = strlen(line_map);
    free (line_map);
    close (fd);
    return (width);
}

int get_map_height(char **argv)
{
    char *line_map;
    int fd;
    int i;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_err();
    while ((line_map = get_next_line(fd)) != NULL)
    {
        i++;
        free(line_map);
    }
    close(fd);
    return (i);
}