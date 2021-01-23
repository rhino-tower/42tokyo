/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:55:47 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/24 01:20:06 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_numlen(long int num, int type)
{
	int base;
	int num_len;

	base = (type == 'x' || type == 'X') ? 16 : 10;
	num_len = (num == 0 ? 1 : 0);
	while (num != 0)
	{
		num_len++;
		num /= base;
	}
	return (num_len);
}

void		size_alloc(long int num, int *num_len, int *space_len, t_format f)
{
	int minus;

	minus = (num < 0 ? 1 : 0);
	*num_len = calc_numlen(num, f.type);
	if (f.width < *num_len)
	{
		*space_len = 0;
		return ;
	}
	if (f.precision == 0 && num == 0)
		*num_len = 0;
	if (f.precision > *num_len)
		*space_len = f.width - f.precision;
	else
		*space_len = f.width - *num_len;
	if (minus)
		(*space_len)--;
}

int			print_int(long num)
{
	int		mod;
	long	div;
	int		print_len;

	print_len = 0;
	mod = num % 10 + '0';
	div = num / 10;
	if (div == 0)
	{
		print_len = write(1, &mod, 1);
	}
	else
	{
		print_len += print_int(div);
		print_len += write(1, &mod, 1);
	}
	return (print_len);
}

static int		calc_mod(unsigned int num, t_format f)
{
	if (f.type == 'x')
		return (num % 16 >= 10 ? (num % 16 - 10) + 'a' : num % 16 + '0');
	else if (f.type == 'X')
		return (num % 16 >= 10 ? (num % 16 - 10) + 'A' : num % 16 + '0');
	return (num % 10 + '0');
}

int			print_u_int(unsigned int num, t_format f)
{
	int				mod;
	unsigned int	div;
	int				base;
	int				print_len;

	base = 10;
	if (f.type == 'x' || f.type == 'X')
		base = 16;
	print_len = 0;
	mod = calc_mod(num, f);
	div = num / base;
	if (div == 0)
	{
		print_len = write(1, &mod, 1);
	}
	else
	{
		print_len += print_u_int(div, f);
		print_len += write(1, &mod, 1);
	}
	return (print_len);
}
