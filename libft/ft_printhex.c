/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:05:44 by chomobon          #+#    #+#             */
/*   Updated: 2024/02/12 18:18:20 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

int	ft_printhex(unsigned int n, int c)
{
	char			*ind;
	unsigned int	base;

	if (c == -1)
		return (-1);
	else
		c = 0;
	ind = "0123456789ABCDEF";
	base = ft_strlen(ind);
	if (n >= base)
	{
		c += ft_printhex(n / base, c);
		if (c == -1)
			return (-1);
		c += ft_printhex(n % base, c);
	}
	else
	{
		c += ft_printcharacter((ind[n % base]));
		if (c == -1)
			return (-1);
	}
	return (c);
}
/* int main()
{
	ft_printhex(200);
} */