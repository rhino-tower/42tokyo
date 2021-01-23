/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:42:03 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/23 23:59:51 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_normal(const char **s)
{
	int i;

	i = 0;
	while ((*s)[i] && (*s)[i] != '%')
		i++;
	write(1, *s, i);
	*s += i;
	return (i);
}

int			print_arg(t_format f, va_list ap)
{
	char *str;

	if (f.type == 's')
	{
		if ((str = (char*)va_arg(ap, char*)) == NULL)
			return (print_s("(null)", f));
		return (print_s(str, f));
	}
	if (f.type == 'c')
		return (print_c((char)va_arg(ap, int), f));
	else if (f.type == 'd' || f.type == 'i')
		return (print_d((int)va_arg(ap, int), f));
	else if (f.type == 'u' || f.type == 'x' || f.type == 'X')
		return (print_u_x((unsigned int)va_arg(ap, unsigned int), f));
	else if (f.type == 'p')
		return (print_pointer((uintptr_t)va_arg(ap, uintptr_t), f));
	else if (f.type == '%')
		return (print_c('%', f));
	return (0);
}

int			format_check(const char **format, va_list *ap, \
			int *output_val)
{
	t_format f;

	(*format)++;
	init_format_val(&f);
	flag_check(format, &f);
	if (**format == ' ')
	{
		(*output_val) += write(1, " ", 1);
		while (**format == ' ')
			(*format)++;
	}
	if (ft_strnchr("0123456789*", **format) != -1)
		if (width_check(format, &f, ap) == ERROR)
			return (ERROR);
	if (**format == '.')
	{
		(*format)++;
		if (precision_check(format, &f, ap) == ERROR)
			return (ERROR);
	}
	if (type_check(format, &f) == ERROR)
		return (ERROR);
	(*output_val) += print_arg(f, *ap);
	return (OK);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		output_val;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	output_val = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (format_check(&format, &ap, &output_val) == ERROR)
				return (ERROR);
			continue;
		}
		output_val += print_normal(&format);
	}
	va_end(ap);
	return (output_val);
}
