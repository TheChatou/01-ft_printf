/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:57:25 by fcoullou          #+#    #+#             */
/*   Updated: 2023/12/11 18:58:05 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hex_size(unsigned long int n)
{
	if (n < 16)
		return (1);
	else
		return (ft_hex_size(n / 16) + ft_hex_size(n % 16));
}

int	ft_int_size(long int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (ft_int_size(n * -1) + 1);
	if (n < 10)
		return (1);
	else
		return (ft_int_size(n / 10) + ft_int_size(n % 10));
}

int	ft_uint_size(unsigned long n)
{
	if (n < 10)
		return (1);
	else
		return (ft_uint_size(n / 10) + ft_uint_size(n % 10));
}
