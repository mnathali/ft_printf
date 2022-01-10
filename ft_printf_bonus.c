/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:53:57 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 20:53:59 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const char	g_flags[] = "cspdiuxX%";

char	*check_string(char *str)
{
	char	*possible;

	possible = "-.0 +#123456789";
	if (!str)
		return (0);
	while (ft_strchr(str, '%'))
	{
		str = ft_strchr(str, '%') + 1;
		while (ft_strchr(possible, *str))
			str++;
		if (!ft_strchr(g_flags, *str))
			return (0);
		str++;
	}
	return (str);
}

int	how_much_will_be_printed(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str && (str[0][i] != '\0' || str[0][i + 1] != '\0'))
	{
		write(1, &str[0][i], 1);
		if (str[0][i] == '\0')
		{
			j++;
			i++;
		}
		i++;
	}
	free(*str);
	return (i - j);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;

	str = (char *)format;
	if (!check_string(str))
		return (-1);
	va_start(args, format);
	str = read_flags(str, &args);
	if (!str)
		return (-1);
	va_end(args);
	return (how_much_will_be_printed(&str));
}
