/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:13:02 by chomobon          #+#    #+#             */
/*   Updated: 2024/02/12 18:17:11 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_write(int *c)
{
	if (*c != -1)
		*c = 0;
	return (*c);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

int	ft_printdec(int n, int c)
{
	char	*ind;

	if (check_write(&c) == -1)
		return (-1);
	ind = "0123456789";
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		c += ft_printcharacter('-');
		if (c == -1)
			return (-1);
		c += ft_printdec(-n, c);
	}
	else if (n >= ft_strlen(ind))
	{
		c += ft_printdec(n / ft_strlen(ind), c);
		if (c == -1)
			return (-1);
		c += ft_printdec(n % ft_strlen(ind), c);
	}
	else if (n < ft_strlen(ind))
		c += ft_printcharacter(ind[n]);
	return (c);
}
/* int main()
{
	ft_printdec(200);
} */