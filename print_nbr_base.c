/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:38:42 by aaammari          #+#    #+#             */
/*   Updated: 2021/12/13 05:32:03 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_hex(unsigned int nb, char a)
{
	char	*base;
	int		len;

	len = 0;
	base = NULL;
	if (a == 'X')
		base = "0123456789ABCDEF";
	else if (a == 'x')
		base = "0123456789abcdef";
	if (nb >= 16)
		len += ft_print_hex(nb / 16, a);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

int	ft_print_p_hex(unsigned long nb, int a)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (a < 2)
	{
		len += write(1, "0x", 2);
		a = len;
	}
	if (nb >= 16)
		len += ft_print_p_hex(nb / 16, a);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

int	ft_nlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb )
{
	char	t;
	int		len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nb >= 0 && nb <= 9)
	{
		t = nb + '0';
		write(1, &t, 1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1);
	}
	else if (nb > 0)
	{
		ft_putnbr(nb / 10);
		t = nb % 10 + '0';
		write(1, &t, 1);
	}
	return (ft_nlen(nb));
}

int	ft_put_u_nbr(unsigned int nb )
{
	char	t;
	int		len;

	len = 0;
	if (nb >= 0 && nb <= 9)
	{
		t = nb + '0';
		len += write(1, &t, 1);
	}
	else if (nb > 0)
	{
		len += ft_put_u_nbr(nb / 10);
		t = nb % 10 + '0';
		len += write(1, &t, 1);
	}
	return (len);
}
