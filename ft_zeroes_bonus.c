/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:56:52 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 21:56:54 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const char	g_flags[] = "cspdiuxX%";

static int	count_i(char *s1, int j, int len)
{
	int	i;

	i = 0;
	while (s1 && s1[i] != '%')
		i++;
	if (j - len > 0)
		i = i + j - len;
	i += len;
	return (i);
}

char	*manage_flags_zero(char *s1, char *s2, int len, int j)
{
	int		i;
	char	*str;
	int		sz;

	sz = len;
	i = count_i(s1, j, len);
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	while (s1 && *s1 != '%')
		*str++ = *s1++;
	while (j - len > 0)
	{
		*str++ = '0';
		j--;
	}
	while (sz > 0)
	{
		*str++ = *s2++;
		sz--;
	}
	*str++ = '\0';
	*str++ = '\0';
	return (str - i - 2);
}

void	reverse_zero_minus(char **str, int i)
{
	char	*btr;

	btr = ft_strrchr(*str, '-');
	*btr = '0';
	while (i > 0)
	{
		btr--;
		i--;
	}
	*btr = '-';
	return ;
}

char	*ft_zeroes(char *btr, long i, int j)
{
	char	*str;
	int		len;
	char	f;

	str = btr;
	while (*btr != '%')
		btr++;
	btr++;
	f = *btr;
	while (!ft_strchr(g_flags, *btr))
		btr++;
	btr = what_inside_par(*btr, i);
	len = ft_strlen_mod(btr, &j);
	if (*btr == '0' && len == 1 && f == '.')
		len = 0;
	str = manage_flags_zero(str, btr, len, j);
	if (j - len > 0 && *btr == '-')
		reverse_zero_minus(&str, j - len);
	free(btr);
	return (str);
}
