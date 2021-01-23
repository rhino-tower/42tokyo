/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:19:16 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/22 22:51:24 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pointer_len(uintptr_t p, t_format f)
{
	int len;

	if (p == 0 && f.precision == 0)
		return (0);
	else if (p == 0)
		return (1);
	len = 0;
	while (p != 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

static void	print_uintptr(uintptr_t p)
{
	uintptr_t	div;
	int			mod;

	mod = ((p % 16 >= 10) ? (p % 16 - 10 + 'a') : (p % 16 + '0'));
	div = p / 16;
	if (div == 0)
	{
		write(1, &mod, 1);
	}
	else
	{
		print_uintptr(div);
		write(1, &mod, 1);
	}
}

int			print_pointer(uintptr_t p, t_format f)
{
	int print_len;

	if (pointer_len(p, f) > f.precision)
		print_len = pointer_len(p, f) + 2;
	else
		print_len = f.precision + 2;
	if (f.f_zero == 1 && f.f_minus != 1)
		print_len += ft_putnchar('0', f.width - print_len);
	else if (f.f_minus != 1)
		print_len += ft_putnchar(' ', f.width - print_len);
	write(1, "0x", 2);
	ft_putnchar('0', f.precision - pointer_len(p, f));
	if (p != 0 || f.precision != 0)
		print_uintptr(p);
	if (f.f_minus == 1)
		print_len += ft_putnchar(' ', f.width - print_len);
	return (print_len);
}
