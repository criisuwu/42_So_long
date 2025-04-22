/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:12:40 by chomobon          #+#    #+#             */
/*   Updated: 2024/02/12 18:19:46 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printstr(char *c)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[i] != '\0')
	{
		comp = write(1, &c[i], 1);
		if (comp == -1)
			return (-1);
		i++;
	}
	return (i);
}

/* int main()
{
	char c[] = "";
	ft_printstr(c);
	return (0);
} */