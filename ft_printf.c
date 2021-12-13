/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:55:38 by aaammari          #+#    #+#             */
/*   Updated: 2021/12/13 02:28:44 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	cat(const char *format, va_list ptr, int i)
{
	int	len;

	len = 0;
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		len += ft_putnbr(va_arg(ptr, int));
	else if (format[i + 1] == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (format[i + 1] == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (format[i + 1] == 'p')
		len += ft_print_p_hex((unsigned long)va_arg(ptr, void *), 0);
	else if (format[i + 1] == 'u')
		len += ft_put_u_nbr(va_arg(ptr, unsigned int));
	else if (format[i + 1] == 'x')
		len += ft_print_hex(va_arg(ptr, unsigned int), 'x');
	else if (format[i + 1] == 'X')
		len += ft_print_hex(va_arg(ptr, unsigned int), 'X');
	else if (format[i + 1] == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	va_start(ptr, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += cat(format, ptr, i);
			i += 2;
		}
		else
		{
			len += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ptr);
	return (len);
}
