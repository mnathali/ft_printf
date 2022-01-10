/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:33:09 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 21:33:12 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const char	g_flags[] = "cspdiuxX%";

static int	count_i(char *s1, int j, int len)
{
	int	i;

	i = 0;
	while (s1[i] != '%')
		i++;
	if (j - len > 0)
		i = i + j - len;
	else if (j + len < 0)
		i = i + (-1) * j - len;
	i += len;
	return (i);
}

static void	divide_func(char **btr, int j, int len)
{
	char	*str;

	str = *btr;
	while (j + len < 0)
	{
		*str++ = ' ';
		j++;
	}
	*str++ = '\0';
	*str++ = '\0';
	*btr = str;
	return ;
}

char	*manage_flags_space(char *s1, char *s2, int len, int j)
{
	int		i;
	char	*str;
	int		sz;

	sz = len;
	i = count_i(s1, j, len);
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	while (*s1 != '%')
		*str++ = *s1++;
	while (j - len > 0)
	{
		*str++ = ' ';
		j--;
	}
	while (sz > 0)
	{
		*str++ = *s2++;
		sz--;
	}
	divide_func(&str, j, len);
	return (str - i - 2);
}

char	*ft_spaces(char *btr, long i, int j, char f)
{
	char	*str;
	char	*take;
	int		len;

	str = btr;
	take = 0;
	btr = ft_strchr(btr, '%') + 1;
	while (!ft_strchr(g_flags, *btr))
	{
		if (*btr == '.')
			take = btr;
		btr++;
	}
	if (*btr == 's' && f == '.')
		j = 0;
	f = *btr;
	btr = what_inside_par(*btr, i);
	len = ft_strlen_mod(btr, &j);
	if (take && len > ft_atoi(take + 1))
		len = ft_atoi(take + 1);
	str = manage_flags_space(str, btr, len, j);
	free(btr);
	return (str);
}
