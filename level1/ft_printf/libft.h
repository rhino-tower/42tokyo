/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:12:13 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/23 11:59:32 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# define OK 1
# define ERROR -1

typedef struct	s_format
{
	int f_minus;
	int f_zero;
	int width;
	int precision;
	int type;
}				t_format;

/*
** printf_utils.c
*/
int				ft_strnchr(const char *str, char c);
int				ft_strlen(const char *str);
int				ft_putstr(const char *str, int n);
int				ft_putnchar(char c, int n);
/*
** print_num_utils.c
*/
void			size_alloc(long int num, int *num_len, int *space_len, \
							t_format f);
int				print_int(long num);
int				print_u_int(unsigned int num, t_format f);
/*
** print_c_s.c
*/
int				print_s(const char *str, t_format f);
int				print_c(char c, t_format f);
/*
** print_num.c
*/
int				print_d(long num, t_format f);
int				print_u_x(unsigned int num, t_format f);
/*
** print_pointer.c
*/
int				print_pointer(uintptr_t p, t_format f);
/*
** format_checker.c
*/
void			init_format_val(t_format *f);
int				flag_check(const char **format, t_format *f);
int				width_check(const char **format, t_format *f,
							va_list *ap);
int				precision_check(const char **format, t_format *f,
							va_list *ap);
int				type_check(const char **format, t_format *f);
/*
** ft_printf
*/
int				format_check(const char **format, va_list *ap, \
							int *output_val);
int				ft_printf(const char *format, ...);

#endif
