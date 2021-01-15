/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:36:12 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/15 22:15:41 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_format_val(t_format *f)
{
	f->f_minus = -1;
	f->f_zero = -1;
	f->width = -1;
	f->precision = -1;
	f->conversions = -1;
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
	if (f->f_minus == 1 && f->f_zero == 1)
	{
		f->f_zero = 0;
		return (ERROR);
	}
	return (OK);
}

int		width_check(const char **format, t_format *f, va_list *ap)
{
	int	width;

	width = 0;
	if (**format == '*')
	{
		f->width = (int)va_arg(*ap, int);
		(*format)++;
	}
	else if ('0' <= **format && **format <= '9')
	{
		while (('0' <= **format && **format <= '9') && **format)
		{
			width = width * 10 + **format - '0';
			(*format)++;
		}
		f->width = width;
	}
	if (ft_strnchr(".cspdiuxX%", **format) == -1)
		return (ERROR);
	return (OK);
}

int		precision_check(const char **format, t_format *f, va_list *ap)
{
	int precision;

	precision = 0;
	if (**format == '*')
	{
		f->precision = (int)va_arg(*ap, int);
		(*format)++;
	}
	else if ('0' <= **format && **format <= '9')
	{
		while (('0' <= **format && **format <= '0') && **format)
		{
			precision = precision * 10 + **format - '0';
			(*format)++;
		}
		f->precision = precision;
	}
	if (ft_strnchr("cspdiuxX%", **format) == -1)
		return (ERROR);
	return (OK);
}

int		conversion_check(const char **format, t_format *f)
{
	if (ft_strnchr("cspdiuxX%", **format) == -1)
		return (ERROR);
	f->conversions = **format;
	(*format)++;
	return (OK);
}
