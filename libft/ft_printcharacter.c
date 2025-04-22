/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcharacter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:34:16 by chomobon          #+#    #+#             */
/*   Updated: 2024/02/09 11:06:31 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int	ft_printcharacter(int c)
{
	return (write(1, &c, 1));
}

/* int main()
{
	char c = 'c';
	ft_printchar(c);
	return(0);
} */