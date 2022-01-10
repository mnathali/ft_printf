/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:04:39 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 22:04:42 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const char	g_flags[] = "cspdiuxX%";

char	*ft_plus_space(char *btr, long i, char f)
{
	char	*str;
	int		len;
	char	spec;

	str = btr;
	while (*btr != '%')
		btr++;
	btr++;
	while (!ft_strchr(g_flags, *btr))
		btr++;
	spec = *btr;
	btr = what_inside_par(*btr, i);
	len = ft_strlen_mod(btr, 0);
	if (((spec == 'i' || spec == 'd') && (int)i >= 0))
	{
		str = manage_flags_space(str, btr, len, len + 1);
		*ft_strrchr(str, ' ') = f;
	}
	else
		str = manage_flags_space(str, btr, len, len);
	free(btr);
	return (str);
}

char	*ft_sharp_flag(char *btr, long i)
{
	char	*str;
	int		len;
	char	spec;

	str = btr;
	while (*btr != '%')
		btr++;
	btr++;
	while (!ft_strchr(g_flags, *btr))
		btr++;
	spec = *btr;
	btr = what_inside_par(*btr, i);
	len = ft_strlen_mod(btr, 0);
	if ((unsigned int)i != 0)
	{
		str = manage_flags_space(str, btr, len, len + 2);
		*ft_strrchr(str, ' ') = spec;
		*ft_strrchr(str, ' ') = '0';
	}
	else
		str = manage_flags_space(str, btr, len, len);
	free(btr);
	return (str);
}

char	*second_bonus(char *btr, long i, char flag)
{
	char	*str;

	str = btr;
	while (*btr != '%')
		btr++;
	btr++;
	while (!ft_strchr(g_flags, *btr))
		btr++;
	if ((flag == ' ' || flag == '+') && *btr != 's')
		str = ft_plus_space(str, i, flag);
	if (flag == ' ' && *btr == 's')
		str = first_bonus(str, i, '5');
	if (flag == '#')
		str = ft_sharp_flag(str, i);
	return (str);
}
