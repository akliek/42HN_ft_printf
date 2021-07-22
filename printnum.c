/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:51:41 by akliek            #+#    #+#             */
/*   Updated: 2021/07/22 13:07:55 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cases(char c)
{
	if (c == '-')
		write(1, "-", 1);
	else if (c == ' ')
		write(1, " ", 1);
	else if (c == '+')
		write(1, "+", 1);
	return (1);
}

static int	if_dash_dot(char *s, int len, t_conversion *conv, int res)
{
	int	l;

	l = len;
	if (*s == '-' || *s == '+' || *s == ' ')
	{
		res += cases(*s);
		s++;
		l -= 1;
	}
	while (conv->num[0] > l && l >= 0)
	{
		write(1, "0", 1);
		res++;
		len++;
		conv->num[0]--;
	}
	s = ahh(s, conv);
	len = aah(s, len);
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
	if ((*s == '-' || *s == '+' || *s == ' ') && conv->num[0] > 0)
		conv->num[0]++;
	if ((conv->num[0] == 0 || conv->num[0] == -1)
		&& ft_strncmp(ahh(s + 1, conv), "0", ft_strlen(ahh(s + 1, conv))) == 0)
		len--;
	while (conv->num[1] > conv->num[0] && conv->num[1] > len)
	{
		write(1, " ", 1);
		res++;
		conv->num[1]--;
	}
	if (*s == '-' || *s == '+' || *s == ' ')
	{
		cases(*s);
		res++;
		s++;
	}
	s = ahh(s, conv);
	len = aah(s, len);
	while (conv->num[0]-- > len)
	{
		write(1, "0", 1);
		res++;
	}
	return (ft_putstr_fd(s, 1) + res);
}

static int	field(char *s, int len, t_conversion *conv, int res)
{
	while (conv->num[0] > len)
	{
		if (conv->zero == 1)
		{
			if (*s == '-' || *s == '+' || *s == ' ')
			{
				cases(*s);
				s++;
				res++;
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

int	print_num(char *s, t_conversion *conv)
{
	int	len;
	int	res;

	res = 0;
	len = ft_strlen(s);
	if (conv->dot == 1 && conv->dash == 1)
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
