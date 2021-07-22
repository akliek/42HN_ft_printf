/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:46:02 by akliek            #+#    #+#             */
/*   Updated: 2021/07/21 14:31:32 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdbool.h>
# include <mm_malloc.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
int		ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n, bool plus, bool space);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
