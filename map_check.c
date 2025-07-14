/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:48:32 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/14 15:05:49 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void is_rectangle(size_t map_w, size_t map_h)
{
    if (map_h < map_w)
        ft_err();
}

void map_is_valid(char *argv)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    if (line[i] != '1')
        ft_err();
    
}