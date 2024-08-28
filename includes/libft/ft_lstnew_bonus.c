/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:41:09 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/05 12:22:32 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Crea una nueva lista; añade el contenido y despues hace que el nodo
//sea igual a null
t_list	*ft_lstnew(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

int main()
{
	t_list *list;
	t_list	*aux;
	char *c = "abcdefg";
	int	i = 0;

	while (c[i] != '\0')
	{
		list = ft_lstnew();
		list->numb = i;
		list->content = c[i];
		list->next = list;
		printf("%d\n", list->numb);
		printf("%c\n", list->content);
		i++;
	}
	return (0);
}