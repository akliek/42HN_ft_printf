/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:47:35 by akliek            #+#    #+#             */
/*   Updated: 2021/07/22 12:56:56 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	aah(char *s, int len)
{
	if (ft_strncmp(s, "", ft_strlen(s)) == 0)
		len = ft_strlen(s);
	return (len);
}

static int	if_dash_dot(char *s, int len, t_conversion *conv, int res)
{
	len = 0;
	while (conv->num[0] > 0 && *s)
	{
		write(1, s, 1);
		s++;
		len++;
		res++;
		conv->num[0]--;
	}
	while (conv->num[1] > len)
	{
		write(1, " ", 1);
		res++;
		conv->num[1]--;
	}
	return (res);
}

static int	if_dot(char *s, int len, t_conversion *conv, int res)
{
	int	l;

	if (len > conv->num[0])
		l = conv->num[0];
	else
		l = len;
	while (conv->num[1] > l)
	{
		write(1, " ", 1);
		res++;
		conv->num[1]--;
	}
	while (*s && conv->num[0] > 0)
	{
		write(1, s, 1);
		s++;
		res++;
		conv->num[0]--;
	}
	return (res);
}

static int	field(char *s, int len, t_conversion *conv, int res)
{
	while (conv->num[0] > len)
	{
		write(1, " ", 1);
		res++;
		conv->num[0]--;
	}
	if (!s)
	{
		write(1, "(null)", 6);
		res += 6;
	}
	else
		res += ft_putstr_fd(s, 1);
	return (res);
}

int	print_string(char *s, t_conversion *conv)
{
	int	len;
	int	res;
	int	check;

	res = 0;
	check = 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		check = 1;
	}
	len = ft_strlen(s);
	if (conv->dot == 1 && conv->dash == 1)
		res += if_dash_dot(s, len, conv, res);
	else if (conv->dot == 1)
		res += if_dot(s, len, conv, res);
	else if (conv->dash == 1)
		res += if_dash(s, len, conv, res);
	else
		res += field(s, len, conv, res);
	if (check == 1)
		free(s);
	return (res);
}
