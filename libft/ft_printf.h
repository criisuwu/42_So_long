/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:19:06 by chomobon          #+#    #+#             */
/*   Updated: 2025/08/14 19:50:11 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printcharacter(int c);
int	ft_printdec(int n, int c);
int	ft_strlenprintf(char *str);
int	ft_printf(char const *str, ...);
int	ft_printhex(unsigned int n, int c);
int	ft_printhexmin(unsigned long n, int c);
int	ft_printpnt(void *i);
int	ft_printstr(char *c);
int	ft_printundec(unsigned int n, int c);
int	check_write(int *c);

#endif