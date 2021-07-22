/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:25:56 by akliek            #+#    #+#             */
/*   Updated: 2021/07/22 12:29:57 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ahh(char *s, t_conversion *conv)
{
	if (conv->dot == 1 && ft_strncmp(s, "0", ft_strlen(s)) == 0
		&& (conv->num[0] == 0 || conv->num[0] == -1))
		s = ft_strdup("");
	return (s);
}

int	if_dash(char *s, int len, t_conversion *conv, int res)
{
	if (conv->pres == 'c')
	{
		write(1, s, 1);
		res = 1;
	}
	else
		res = ft_putstr_fd(s, 1);
	while (conv->num[0] > len)
	{
		write(1, " ", 1);
		conv->num[0]--;
		res++;
	}
	return (res);
}

int	print_char(char *s, t_conversion *conv)
{
	int	res;

	res = 0;
	if (conv->dash == 1)
		return (if_dash(s, 1, conv, res));
	while (conv->num[0] > 1)
	{
		if (conv->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		res++;
		conv->num[0]--;
	}
	write(1, s, 1);
	res++;
	return (res);
}

int	print_percent(char *s, t_conversion *conv, int res)
{
	if (conv->dash == 1 && conv->dot == 1)
	{
		res += ft_putstr_fd(s, 1);
		while (conv->num[1]-- > 1)
		{
			write(1, " ", 1);
			res++;
		}
	}
	else if (conv->dash == 1)
		return (if_dash(s, 1, conv, res));
	else if (conv->dot == 1)
	{
		while (conv->num[1]-- > 1)
		{
			write(1, " ", 1);
			res++;
		}
		res += ft_putstr_fd(s, 1);
	}
	else
		res += print_char(s, conv);
	return (res);
}
