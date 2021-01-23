/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:36:12 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/24 00:56:26 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_format_val(t_format *f)
{
	f->f_minus = -1;
	f->f_zero = -1;
	f->width = -1;
	f->precision = -1;
	f->type = -1;
}

int		flag_check(const char **format, t_format *f)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			f->f_minus = 1;
		else if (**format == '0')
			f->f_zero = 1;
		(*format)++;
	}
	return (OK);
}

int		width_check(const char **format, t_format *f, va_list *ap)
{
	if (**format == '*')
	{
		f->width = (int)va_arg(*ap, int);
		(*format)++;
	}
	else if ('0' <= **format && **format <= '9')
	{
		f->width = 0;
		while (('0' <= **format && **format <= '9') && **format)
		{
			f->width = f->width * 10 + **format - '0';
			(*format)++;
		}
	}
	if (ft_strnchr(".cspdiuxX%", **format) == -1 || f->width >= INT_MAX - 1 \
		|| f->width <= INT_MIN + 1)
		return (ERROR);
	if (f->width < 0)
	{
		f->width *= -1;
		f->f_minus = 1;
	}
	return (OK);
}

int		precision_check(const char **format, t_format *f, va_list *ap)
{
	if (f->type == 'c' && ft_strnchr("*0123456789", **format) >= 0)
		return (ERROR);
	f->precision = 0;
	if (**format == '*')
	{
		f->precision = (int)va_arg(*ap, int);
		(*format)++;
	}
	else if ('0' <= **format && **format <= '9')
	{
		while (('0' <= **format && **format <= '9') && **format)
		{
			f->precision = f->precision * 10 + **format - '0';
			(*format)++;
		}
	}
	if (ft_strnchr("cspdiuxX%", **format) == -1)
		return (ERROR);
	return (OK);
}

int		type_check(const char **format, t_format *f)
{
	if (ft_strnchr("cspdiuxX%", **format) == -1)
		return (ERROR);
	f->type = **format;
	(*format)++;
	return (OK);
}
