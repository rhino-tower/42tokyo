/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:22:47 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/24 01:16:04 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_d(long num, t_format f)
{
	int	num_len;
	int	space_len;
	int	print_len;

	print_len = 0;
	size_alloc(num, &num_len, &space_len, f);
	if (f.f_minus != 1 && f.f_zero != 1)
		print_len += ft_putnchar(' ', space_len);
	else if (f.f_zero == 1 && f.precision >= 0 && f.f_minus != 1)
		print_len += ft_putnchar(' ', space_len);
	if (num < 0)
		print_len += write(1, "-", 1);
	num = (num < 0 ? -1 * num : num);
	if (f.f_zero == 1 && f.precision < 0 && f.f_minus != 1)
		print_len += ft_putnchar('0', space_len);
	print_len += ft_putnchar('0', f.precision - num_len);
	if (f.precision != 0 || num != 0)
		print_len += print_int(num);
	if (f.f_minus == 1)
		print_len += ft_putnchar(' ', space_len);
	return (print_len);
}

int		print_u_x(unsigned int num, t_format f)
{
	int	num_len;
	int	space_len;
	int	print_len;

	print_len = 0;
	size_alloc(num, &num_len, &space_len, f);
	if (f.f_minus != 1 && f.f_zero != 1)
		print_len += ft_putnchar(' ', space_len);
	else if (f.f_zero == 1 && f.precision >= 0 && f.f_minus != 1)
		print_len += ft_putnchar(' ', space_len);
	if (f.f_zero == 1 && f.precision < 0)
		print_len += ft_putnchar('0', space_len);
	print_len += ft_putnchar('0', f.precision - num_len);
	if (f.precision != 0 || num != 0)
		print_len += print_u_int(num, f);
	if (f.f_minus == 1)
		print_len += ft_putnchar(' ', space_len);
	return (print_len);
}
