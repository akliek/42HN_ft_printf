/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:10:57 by akliek            #+#    #+#             */
/*   Updated: 2021/07/22 12:29:04 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cases(char c)
{
	if (c == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	return (2);
}

static int	if_dash_dot(char *s, int len, t_conversion *conv, int res)
{
	int	l;

	l = 0;
	if (conv->pres == 'p' || conv->sharp == 1)
	{
		l = cases(conv->pres);
		res += 2;
		s += 2;
	}
	s = ahh(s, conv);
	l = len - l;
	while (conv->num[0]-- > l)
	{
		write(1, "0", 1);
		res++;
		len++;
	}
	res += ft_putstr_fd(s, 1);
	while (conv->num[1]-- > len)
	{
		write(1, " ", 1);
		res++;
	}
	return (res);
}

static int	if_dot(char *s, int len, t_conversion *conv, int res)
{
	if (conv->pres == 'p' || conv->sharp == 1)
		conv->num[0] += 2;
	while (conv->num[1] > conv->num[0] && conv->num[1] > len)
	{
		write(1, " ", 1);
		res++;
		conv->num[1]--;
	}
	if (conv->pres == 'p' || conv->sharp == 1)
	{
		cases(conv->pres);
		res += 2;
		s += 2;
	}
	s = ahh(s, conv);
	while (conv->num[0] > len)
	{
		write(1, "0", 1);
		res++;
		conv->num[0]--;
	}
	res += ft_putstr_fd(s, 1);
	return (res);
}

static int	field(char *s, int len, t_conversion *conv, int res)
{
	bool	check;

	check = 0;
	while (conv->num[0] > len)
	{
		if (conv->zero == 1)
		{
			if ((conv->pres == 'p' || conv->sharp == 1) && check == 0)
			{
				cases(conv->pres);
				res += 2;
				s += 2;
				check = 1;
			}
			write(1, "0", 1);
		}
		else
			write(1, " ", 1);
		res++;
		conv->num[0]--;
	}
	res += ft_putstr_fd(s, 1);
	return (res);
}

int	print_hex_pointer(char *s, t_conversion *conv)
{
	int	res;
	int	len;

	res = 0;
	if (conv->pres == 'p' && !s)
		s = ft_strdup("0x0");
	if (conv->dot == 1 && ft_strncmp(s, "0", ft_strlen(s)) == 0
		&& (conv->num[0] == 0 || conv->num[0] == -1))
	{
		free(s);
		s = ft_strdup("");
	}
	len = ft_strlen(s);
	if (conv->dash == 1 && conv->dot == 1)
		res += if_dash_dot(s, len, conv, res);
	else if (conv->dot == 1)
		res += if_dot(s, len, conv, res);
	else if (conv->dash == 1)
		res += if_dash(s, len, conv, res);
	else
		res += field(s, len, conv, res);
	free(s);
	return (res);
}
