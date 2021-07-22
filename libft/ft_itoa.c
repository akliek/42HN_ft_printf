/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:43:36 by akliek            #+#    #+#             */
/*   Updated: 2021/07/21 14:30:51 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n, int len)
{
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*get_itoa(int len, int n, int plus, int space)
{
	char	*res;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (--len >= 0 && n >= 1)
	{
		res[len] = n % 10 + 48;
		n /= 10;
	}
	if (plus == 1)
		res[0] = '+';
	else if (space == 1)
		res[0] = ' ';
	else if (len == 0)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n, bool plus, bool space)
{
	int		len;

	len = 0;
	if (n > 0 && (plus == 1 || space == 1))
		len++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		if (plus == 1)
			return (ft_strdup("+0"));
		else if (space == 1)
			return (ft_strdup(" 0"));
		else
			return (ft_strdup("0"));
	}
	len = num_len(n, len);
	if (n < 0)
	{
		n *= -1;
		plus = 0;
		space = 0;
	}
	return (get_itoa(len, n, plus, space));
}
