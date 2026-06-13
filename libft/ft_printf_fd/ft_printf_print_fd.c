/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:57:17 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/13 13:29:25 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	print_c(int fd, int c)
{
	return (write(fd, &c, 1));
}

int	print_s(int fd, char *str)
{
	int	count;

	if (!str)
		return (write(fd, "(null)", 6));
	count = write(fd, str, ft_strlen(str));
	return (count);
}

int	print_di(int fd, t_format *fmt, int n)
{
	int	count;

	count = 0;
	if (n >= 0 && fmt->flag_plus)
		count += write(fd, "+", 1);
	if (n >= 0 && fmt->flag_space && !fmt->flag_plus)
		count += write(fd, " ", 1);
	count += ft_putnbr_base(fd, n, BASE10);
	return (count);
}

int	print_p(int fd, void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (write(fd, PTR_NULL, ft_strlen(PTR_NULL)));
	count += write(fd, "0x", 2);
	count += ft_putnbr_ubase(fd, (unsigned long)p, BASE16_LOWER);
	return (count);
}

int	print_hexa(int fd, t_format *fmt, unsigned int u)
{
	int	count;

	count = 0;
	if (fmt->specifier == 'x')
	{
		if (u > 0 && fmt->flag_hash)
			count += write(fd, "0x", 2);
		count += ft_putnbr_ubase(fd, u, BASE16_LOWER);
	}
	else
	{
		if (u > 0 && fmt->flag_hash)
			count += write(fd, "0X", 2);
		count += ft_putnbr_ubase(fd, u, BASE16_UPPER);
	}
	return (count);
}
