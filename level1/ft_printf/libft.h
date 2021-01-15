/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:12:13 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/15 21:15:27 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# define OK 1
# define ERROR -1

typedef struct	s_format
{
	int f_minus;
	int f_zero;
	int width;
	int precision;
	int conversions;
}				t_format;

/*
** utils.c
*/
int				ft_putstr(const char *str);
int				ft_strnchr(const char *str, char c);
int				ft_strlen(const char *str);
int				ft_putnchar(char c, int n);
/*
** format_checker.c
*/
void			init_format_val(t_format *f);
int				flag_check(const char **format, t_format *f);
int				width_check(const char **format, t_format *f,
							va_list *ap);
int				precision_check(const char **format, t_format *f,
							va_list *ap);
int				conversion_check(const char **format, t_format *f);
/*
** ft_printf
*/
int				format_check(const char **format, va_list *ap);
int				ft_printf(const char *format, ...);

#endif
