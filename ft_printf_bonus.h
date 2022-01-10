/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:29:43 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/24 20:09:24 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
char	*check_string(char *str);
char	*ft_strchr(const char *s, int c);
char	*read_flags(char *str, va_list *dest);
char	*what_is_flag(char **str, char **btr, long i);
void	next_flag(char **str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_itoa_pointer(unsigned long int n);
char	*ft_itoa_signed(int n);
char	*ft_itoa_unsigned(unsigned int n, char a);
int		ft_strlen_mod(const char *str, int *j);
size_t	ft_strlen(const char *str);
char	*ft_strdup_mod(char *s1);
char	*ft_strjoin_another(char const *s1, char const *s2);
char	*ft_strjoin_mod(char const *s1, char const *s2);
char	*what_is_after(char *str, long int i, char a);
char	*what_inside_par(char a, long int i);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(char *str);
char	*first_bonus(char *btr, long i, char flag);
char	*first_step(int j, long i, char f);
char	*manage_double_flag(char *btr, long i, int j, char f);
char	*manage_flags_space(char *s1, char *s2, int len, int j);
char	*ft_spaces(char *btr, long i, int j, char f);
char	*ft_zeroes(char *btr, long i, int j);
void	reverse_zero_minus(char **str, int i);
char	*second_bonus(char *btr, long i, char flag);
char	*ft_sharp_flag(char *btr, long i);
char	*ft_plus_space(char *btr, long i, char f);
char	*manage_flags_zero(char *s1, char *s2, int len, int j);

#endif
