/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:13:37 by chomobon          #+#    #+#             */
/*   Updated: 2025/07/29 14:24:54 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_err_arg()
{
    ft_putendl_fd("ARG ERROR", 2);
    exit(EXIT_FAILURE);
}

void ft_err(int option)
{
    if (option == 1)
    {
        ft_putendl_fd("MEMORY ERROR", 2);
        exit(EXIT_FAILURE);
    }
    else if(option == 2)
    {
        ft_putendl_fd("OPEN FILE ERROR", 2);
        exit(EXIT_FAILURE);
    }
    else if(option == 3)
    {
        ft_putendl_fd("MAP ERROR", 2);
        exit(EXIT_FAILURE);
    }
    else if(option == 4)
    {
        ft_putendl_fd("TOO MANY OBJECTS", 2);
        exit(EXIT_FAILURE);
    }
}
