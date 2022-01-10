/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:26:39 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 21:26:43 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const char	g_flags[] = "cspdiuxX%";

char	*first_step(int j, long i, char f)
{
	char	*str;
	char	*btr;
	int		len;

	str = what_inside_par(f, i);
	btr = str;
	len = ft_strlen_mod(str, &j);
	if (*str == '0' && len == 1)
		len = 0;
	str = manage_flags_zero(0, str, len, j);
	if (j - len > 0 && *btr == '-')
		reverse_zero_minus(&str, j - len);
	free(btr);
	return (str);
}

char	*manage_double_flag(char *btr, long i, int j, char f)
{
	char	*str;
	int		len;

	str = btr;
	while (*btr != '%')
		btr++;
	len = ft_atoi(ft_strchr(btr, '.') + 1);
	btr++;
	while (!ft_strchr(g_flags, *btr))
		btr++;
	if (*btr == 's')
		return (ft_spaces(str, i, j, f));
	if ((*btr == 'd' || *btr == 'i') && (int)i < 0)
		len++;
	btr = first_step(len, i, *btr);
	len = ft_strlen_mod(btr, &j);
	str = manage_flags_space(str, btr, len, j);
	free (btr);
	return (str);
}

char	*first_bonus(char *btr, long i, char f)
{
	char	*str;
	int		j;

	str = btr;
	while (*btr != '%')
		btr++;
	btr++;
	while (*(btr + 1) == '-' || (f == '.' && *btr == '.'))
		btr++;
	j = ft_atoi(btr);
	while (!ft_strchr(g_flags, *btr))
	{
		if (*btr == '.')
			return (manage_double_flag(str, i, j, f));
		btr++;
	}
	if (f == '.' && (*btr == 'd' || *btr == 'i') && (int)i < 0)
		j++;
	if (((f == '-' || (f > '0' && f <= '9'))) || (*btr == 's' && f == '.'))
		str = ft_spaces(str, i, j, f);
	if (f == '.' && *btr == '%')
		j = 0;
	if (f == '0' || (f == '.' && *btr != 's'))
		str = ft_zeroes(str, i, j);
	return (str);
}
