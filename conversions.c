/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:37:51 by akliek            #+#    #+#             */
/*   Updated: 2021/07/21 17:45:12 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	delete_struct(t_conversion *conv)
{
	conv->pres = '\0';
	conv->dash = 0;
	conv->dot = 0;
	conv->num[0] = 0;
	conv->num[1] = 0;
	conv->plus = 0;
	conv->plus = 0;
	conv->space = 0;
	conv->zero = 0;
	free(conv);
}

static char	*get_itoh(unsigned long n, t_conversion *conv, int len)
{
	char	*hex;

	hex = (char *)malloc((len + 1) * sizeof(char));
	hex[len] = '\0';
	while (n > 0)
	{
		len--;
		if (n % 16 > 9 && (conv->pres == 'x' || conv->pres == 'p'))
			hex[len] = n % 16 + 87;
		else if (n % 16 > 9 && conv->pres == 'X')
			hex[len] = n % 16 + 55;
		else
			hex[len] = n % 16 + 48;
		n /= 16;
	}
	if (conv->pres == 'p' || conv->sharp == 1)
	{
		hex[0] = '0';
		if (conv->pres == 'x' || conv->pres == 'p')
			hex[1] = 'x';
		if (conv->pres == 'X')
			hex[1] = 'X';
	}
	return (hex);
}

static char	*itoh(unsigned long n, t_conversion *conv)
{
	int				len;
	unsigned long	tmp;

	if (conv->pres == 'x' || conv->pres == 'X')
		n = (unsigned int)n;
	len = 0;
	if (conv->pres == 'p' || conv->sharp == 1)
		len = 2;
	if (n == 0)
	{
		if (conv->pres == 'p')
			return (ft_strdup("0x0"));
		else
			return (ft_strdup("0"));
	}
	if (n < 0)
		n *= -1;
	tmp = n;
	while (tmp > 0)
	{
		len++;
		tmp /= 16;
	}
	return (get_itoh(n, conv, len));
}

static char	*utoa(unsigned int n)
{
	char			*res;
	int				len;
	unsigned int	tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp >= 1)
	{
		tmp /= 10;
		len++;
	}
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (--len >= 0 && n >= 1)
	{
		res[len] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}

int	get_conversion(va_list args, t_conversion *conv, char c)
{
	int				res;
	unsigned char	s;

	res = 0;
	conv->pres = c;
	if (conv->pres == 'c')
	{
		s = (unsigned char)va_arg(args, int);
		res = print_char((char *)&s, conv);
	}
	else if (conv->pres == 's')
		res = print_string(va_arg(args, char *), conv);
	else if (conv->pres == 'd' || conv->pres == 'i')
		res = print_num(ft_itoa(va_arg(args, int), conv->plus,
					conv->space), conv);
	else if (conv->pres == 'u')
		res = print_num(utoa(va_arg(args, unsigned int)), conv);
	else if (conv->pres == 'x' || conv->pres == 'X' || conv->pres == 'p')
		res = print_hex_pointer(itoh(va_arg(args, unsigned long), conv), conv);
	else
		res = print_percent("%", conv, res);
	delete_struct(conv);
	return (res);
}
