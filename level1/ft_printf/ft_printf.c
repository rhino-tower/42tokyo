/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:42:03 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/15 22:18:50 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_str(const char **s)
{
	int i;

	i = 0;
	while ((*s)[i] && (*s)[i] != '%')
		i++;
	write(1, *s, i);
	*s += i;
	return (i);
}

int		print_arg(t_format f, va_list ap)
{
	char	*str;

	if (f.conversions == 's')
		str = (char *)va_arg(ap, char*);
	if (ft_strlen(str) >= f.width)
	{
		return (ft_putstr(str));
	}
	else
	{
		if (f.f_minus == 1)
		{
			if (f.f_zero == 1)
				ft_putnchar('0', f.width - ft_strlen(str));
			else
				ft_putnchar(' ', f.width - ft_strlen(str));
			ft_putstr(str);
		}
		else
		{
			ft_putstr(str);
			if (f.f_zero == 1)
				ft_putnchar('0', f.width - ft_strlen(str));
			else
				ft_putnchar(' ', f.width - ft_strlen(str));
		}
	}
	return (f.width);
}

int		format_check(const char **format, va_list *ap)
{
	t_format f;

	(*format)++;
	init_format_val(&f);
	if (flag_check(format, &f) == ERROR)
		return (ERROR);
	if (width_check(format, &f, ap) == ERROR)
		return (ERROR);
	if (**format == '.')
	{
		(*format)++;
		if (precision_check(format, &f, ap) == ERROR)
			return (ERROR);
	}
	if (conversion_check(format, &f) == ERROR)
		return (ERROR);
	print_arg(f, *ap);
	return (0);
}

int		ft_printf(const char *format, ...)
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
			format_check(&format, &ap);
		else
			output_val += print_str(&format);
	}
	va_end(ap);
	return (output_val);
}
