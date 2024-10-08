/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:16:04 by chomobon          #+#    #+#             */
/*   Updated: 2023/09/19 15:40:46 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
	{
		return (i + 32);
	}
	return (i);
}

/*int	main(void)
{
	char a[] = "AWEVO";
	printf("%s\n", ft_strlowcase(a));
}*/
