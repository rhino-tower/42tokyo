/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:18:19 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/24 00:01:16 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_s(const char *str, t_format f)
{
	int len;
	int print_len;

	len = ft_strlen(str);
	print_len = 0;
	if (f.f_minus == 1)
	{
		print_len = ft_putstr(str, f.precision);
		print_len += ft_putnchar(' ', f.width - print_len);
	}
	else
	{
		if (f.precision >= 0)
			len = (len <= f.precision ? len : f.precision);
		if (f.f_zero == 1)
			print_len += ft_putnchar('0', f.width - len);
		else
			print_len += ft_putnchar(' ', f.width - len);
		print_len += ft_putstr(str, f.precision);
	}
	return (print_len);
}

int		print_c(char c, t_format f)
{
	int print_len;

	print_len = 0;
	if (f.f_minus == 1)
	{
		print_len = write(1, &c, 1);
		print_len += ft_putnchar(' ', f.width - print_len);
	}
	else
	{
		if (f.f_zero == 1)
			print_len += ft_putnchar('0', f.width - 1);
		else
			print_len = ft_putnchar(' ', f.width - 1);
		print_len += write(1, &c, 1);
	}
	return (print_len);
}
