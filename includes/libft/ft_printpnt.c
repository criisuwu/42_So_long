/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:34 by chomobon          #+#    #+#             */
/*   Updated: 2024/02/12 18:19:14 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_printpnt(void *i)
{
	unsigned long	n;
	int				c;

	n = (unsigned long) i;
	c = 0;
	c += write(1, "0x", 2);
	if (c == -1)
		return (-1);
	c += ft_printhexmin(n, 0);
	if (c == -1)
		return (-1);
	return (c);
}

/* int main()
{
	void *c = "heayasd";
	ft_printpnt(c);
	printf("\n");
	printf("%p\n", c);
} */