# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnathali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 18:29:57 by mnathali          #+#    #+#              #
#    Updated: 2021/12/23 18:29:59 by mnathali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PHEADER = ft_printf.h

BONH = ft_printf_bonus.h

POSITION = -a

BONP = -b

PSRC = 	ft_itoa_unsigned.c ft_what_is_after.c\
		ft_itoa_pointer.c ft_libft_mod.c ft_itoa_signed.c\
		ft_what_inside_par.c ft_printf.c ft_read_flags.c

BONS =	ft_itoa_unsigned.c ft_what_is_after.c\
		ft_itoa_pointer.c ft_libft_mod.c ft_itoa_signed.c\
		ft_what_inside_par.c\
		ft_first_bonus.c ft_zeroes_bonus.c ft_second_bonus.c\
		ft_spaces_bonus.c ft_printf_bonus.c\
		ft_read_flags_bonus.c

LIBFT = libft/libft.a

LIBSRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
	  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c

OBJSRC = $(patsubst %.c, %.o, $(PSRC))

BONOBJSRC = $(patsubst %.c, %.o, $(BONS))

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

%.o : %.c $(PHEADER) $(LIBFT)
	$(CC) $(FLAGS) -c $<

$(LIBFT): $(patsubst ft_%, libft/ft_%, $(LIBSRC)) libft/libft.h
	cd libft && $(MAKE)
	cp $(LIBFT) $(NAME)

$(NAME): $(OBJSRC)
	ar rcs $(POSITION) ft_isalpha.o $(NAME) $?

clean:
	rm -rf $(OBJSRC) $(BONOBJSRC)
	cd libft && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all

bonus:
	@make PSRC="$(BONS)" PHEADER="$(BONH)" POSITION="$(BONP)" all

.PHONY: all clean fclean re bonus