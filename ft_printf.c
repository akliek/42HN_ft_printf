/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:35:53 by akliek            #+#    #+#             */
/*   Updated: 2021/07/22 14:14:48 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*find_conversion(const char *format)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (ft_strchr("cspdiuxX%", format[i]) == NULL)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		str[j] = *format;
		j++;
		format++;
	}
	str[j] = '\0';
	return (str);
}

static t_conversion	*num_init(t_conversion *conv, char *str, int i, int j)
{
	int	tmp;

	if (conv->num[0] == -1)
		conv->num[0] = 0;
	if (conv->num[1] == -1)
		conv->num[1] = 0;
	if (conv->dot == 1 || conv->dash == 1)
	{
		while (ft_isdigit(str[i]))
		{	
			conv->num[1] += (str[i] - 48) * j;
			j *= 10;
			i--;
		}
	}
	while (ft_isdigit(str[i]))
	{
		tmp = i - 1;
		if ((tmp < 0 || !ft_isdigit(str[tmp])) && str[i] == '0')
			conv->zero = 1;
		conv->num[0] += (str[i] - 48) * j;
		j *= 10;
		i--;
	}
	return (conv);
}

static t_conversion	*conversion_init(t_conversion *conv, char *str, int j)
{
	int	i;

	i = ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] == '.')
			conv->dot = 1;
		else if (str[i] == '-')
			conv->dash = 1;
		else if (str[i] == '#')
			conv->sharp = 1;
		else if (str[i] == ' ')
			conv->space = 1;
		else if (str[i] == '+')
			conv->plus = 1;
		else if (ft_isdigit(str[i]))
		{
			conv = num_init(conv, str, i, j);
			while (ft_isdigit(str[i]))
				i--;
			i++;
		}
	}
	return (conv);
}

static t_conversion	*parse_conversion(const char *format)
{
	t_conversion	*conv;
	char			*str;
	int				j;

	j = 1;
	conv = (t_conversion *)malloc(sizeof(t_conversion));
	str = find_conversion(format);
	conv->num[0] = -1;
	conv->num[1] = -1;
	conv = conversion_init(conv, str, j);
	free(str);
	return (conv);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				res;
	t_conversion	*conv;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			conv = parse_conversion(format);
			while (ft_strchr("cspdiuxX%", *format) == NULL)
				format++;
			res += get_conversion(args, conv, *format);
		}
		else
		{
			write(1, format, 1);
			res++;
		}
		format++;
	}
	va_end(args);
	return (res);
}
