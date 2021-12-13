/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:33:57 by aaammari          #+#    #+#             */
/*   Updated: 2021/12/13 02:28:58 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_print_hex(unsigned int nb, char a);
int	ft_print_p_hex(unsigned long nb, int a);
int	ft_putnbr(int nb );
int	ft_put_u_nbr(unsigned int nb );
int	ft_printf(const char *format, ...);

#endif