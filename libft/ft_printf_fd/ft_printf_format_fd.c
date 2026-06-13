/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 07:41:42 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/13 13:30:22 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_format_fd(int fd, t_format *fmt, va_list *args)
{
	int	count;

	count = 0;
	if (fmt->specifier == 'c')
		count += print_c(fd, va_arg(*args, int));
	else if (fmt->specifier == 's')
		count += print_s(fd, va_arg(*args, char *));
	else if (fmt->specifier == 'p')
		count += print_p(fd, va_arg(*args, void *));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		count += print_di(fd, fmt, va_arg(*args, int));
	else if (fmt->specifier == 'u')
		count += ft_putnbr_ubase(fd, va_arg(*args, unsigned int), BASE10);
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		count += print_hexa(fd, fmt, va_arg(*args, unsigned int));
	else if (fmt->specifier == '%')
		count += write(fd, "%", 1);
	return (count);
}
