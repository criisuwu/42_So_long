/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printundec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:19:27 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 19:53:15 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printundec(unsigned int n, int c)
{
	char			*ind;
	unsigned int	base;

	if (c == -1)
		return (-1);
	else
		c = 0;
	ind = "0123456789";
	base = ft_strlenprintf(ind);
	if (n >= base)
	{
		c += ft_printundec(n / base, c);
		if (c == -1)
			return (-1);
		c += ft_printundec(n % base, c);
	}
	if (n < base)
	{
		c += ft_printcharacter((ind[n % base]));
		if (c == -1)
			return (-1);
	}
	return (c);
}
/* int main()
{
	ft_printundec(2023);
} */