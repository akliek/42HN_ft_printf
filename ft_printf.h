/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:40:50 by akliek            #+#    #+#             */
/*   Updated: 2021/07/22 12:57:28 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_conversion
{
	char		pres;
	int			num[2];
	bool		dash;
	bool		dot;
	bool		zero;
	bool		sharp;
	bool		plus;
	bool		space;
}				t_conversion;

int				print(char *s, t_conversion *conv);
int				ft_printf(const char *format, ...);
int				get_conversion(va_list args, t_conversion *conv, char c);
int				print_num(char *s, t_conversion *conv);
int				if_dash(char *s, int len, t_conversion *conv, int res);
int				print_hex_pointer(char *s, t_conversion *conv);
int				print_string(char *s, t_conversion *conv);
int				print_char(char *s, t_conversion *conv);
int				print_percent(char *s, t_conversion *conv, int res);
char			*ahh(char *s, t_conversion *conv);
int				aah(char *s, int len);

#endif
