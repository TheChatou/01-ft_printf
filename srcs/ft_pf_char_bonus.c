/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:48:15 by fcoullou          #+#    #+#             */
/*   Updated: 2023/12/11 20:32:34 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_p_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_pf_char(char c, t_print *tab)
{
	int	count;

	count = 0;
	if (tab->dash)
		count += ft_p_char(c);
	count += ft_fill_z_s(tab->wdt, 1, 0);
	if (!tab->dash)
		count += ft_p_char(c);
	return (count);
}
