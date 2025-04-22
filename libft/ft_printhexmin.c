/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexmin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:10:01 by chomobon          #+#    #+#             */
/*   Updated: 2024/02/12 18:18:56 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

int	ft_printhexmin(unsigned long n, int c)
{
	char			*ind;
	unsigned int	base;

	if (c == -1)
		return (-1);
	else
		c = 0;
	ind = "0123456789abcdef";
	base = ft_strlen(ind);
	if (n >= base)
	{
		c += ft_printhexmin(n / base, c);
		if (c == -1)
			return (-1);
		c += ft_printhexmin(n % base, c);
	}
	else
	{
		c += ft_printcharacter((ind[n]));
		if (c == -1)
			return (-1);
	}
	return (c);
}
/* int main()
{
	ft_printhexmin(33);
} */