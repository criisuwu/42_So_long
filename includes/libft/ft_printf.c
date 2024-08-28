/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:57 by chomobon          #+#    #+#             */
/*   Updated: 2024/02/12 18:17:44 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	det_porcentajes(char const str, va_list args)
{
	int	count;

	count = 0;
	if (str == 'c')
		count = ft_printcharacter(va_arg(args, int));
	else if (str == 's')
		count = ft_printstr(va_arg(args, char *));
	else if (str == 'p')
		count = ft_printpnt(va_arg(args, void *));
	else if (str == 'd' || str == 'i')
		count = ft_printdec(va_arg(args, int), 0);
	else if (str == 'u')
		count = ft_printundec(va_arg(args, unsigned int), 0);
	else if (str == 'X')
		count = ft_printhex(va_arg(args, unsigned int), 0);
	else if (str == 'x')
		count = ft_printhexmin(va_arg(args, unsigned int), 0);
	else if (str == '%')
	{
		count = write(1, "%", 1);
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		contador;

	contador = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			contador += det_porcentajes(str[++i], args);
			if (contador == -1)
				return (-1);
		}
		else
		{
			contador += write(1, &str[i], 1);
			if (contador == -1)
				return (-1);
		}
		i++;
	}
	return (contador);
}

/* int main(){
	int a, b;

	a = ft_printf("hola mundo");
	printf("\n");
	b = printf("hola mundo");

	printf("%d", a);
	printf("%d", b);
} */