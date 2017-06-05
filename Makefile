# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpachy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/05 15:32:15 by hpachy            #+#    #+#              #
#    Updated: 2017/04/05 15:32:16 by hpachy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCDIR			= srcs/
INCDIR			= includes/

SRC 			= 	ft_printf.c \
					parser.c \
					checker_flags_1.c \
					checker_flags_2.c \
					checker_conversion_1.c \
					checker_conversion_2.c \
					checker_conversion_3.c \
					checker_conversion_4.c \
					fonction_app_flags1.c \
					fonction_app_flags2.c \
					init_flags.c \
					tab_gestion.c \
					fonction_app_precision.c \
					fonction_padding_app.c \
					fonction_flags_modificateur1.c \
					fonction_flags_modificateur2.c \
					fonction_flags_modificateur3.c \
					libft/ft_putchar.c \
					libft/ft_strcat.c \
					libft/ft_strcmp.c \
					libft/ft_strcpy.c \
					libft/ft_strdup.c \
					libft/ft_strlen.c \
					libft/ft_strncpy.c \
					libft/ft_strncat.c \
					libft/ft_atoi.c \
					libft/ft_isalpha.c \
					libft/ft_isdigit.c \
					libft/ft_isalnum.c \
					libft/ft_isascii.c \
					libft/ft_isprint.c \
					libft/ft_toupper.c \
					libft/ft_tolower.c \
					libft/ft_strstr.c \
					libft/ft_strnstr.c \
					libft/ft_strnstr.c \
					libft/ft_strncmp.c \
					libft/ft_strchr.c \
					libft/ft_strrchr.c \
					libft/ft_memset.c \
					libft/ft_bzero.c \
					libft/ft_memcpy.c \
					libft/ft_memchr.c \
					libft/ft_memccpy.c \
					libft/ft_putnbr.c \
					libft/ft_putnbr_fd.c \
					libft/ft_putchar_fd.c \
					libft/ft_putstr.c \
					libft/ft_putstr_fd.c \
					libft/ft_putendl.c \
					libft/ft_putendl_fd.c \
					libft/ft_memalloc.c \
					libft/ft_memdel.c \
					libft/ft_strnew.c \
					libft/ft_strdel.c \
					libft/ft_strclr.c \
					libft/ft_striter.c \
					libft/ft_striteri.c \
					libft/ft_strmap.c \
					libft/ft_strmapi.c \
					libft/ft_strequ.c \
					libft/ft_strnequ.c \
					libft/ft_strsub.c \
					libft/ft_strjoin.c \
					libft/ft_memcmp.c \
					libft/ft_strtrim.c \
					libft/ft_strsplit.c \
					libft/ft_itoa.c \
					libft/ft_itoa.c \
					libft/ft_memmove.c \
					libft/ft_strlcat.c \
					libft/ft_lstdelone.c \
					libft/ft_lstnew.c \
					libft/ft_lstdel.c \
					libft/ft_lstadd.c \
					libft/ft_lstiter.c \
					libft/ft_lstmap.c \
					libft/ft_intlen.c \
					libft/ft_isspace.c \
					libft/ft_add_end.c \
					libft/get_next_line.c \
					libft/ft_itoa_base.c \
					libft/ft_c_strnew.c \
					libft/ft_itoa_intmax_t.c \
					libft/ft_itoa_long_long.c \
					libft/ft_itoa_long.c \
					libft/ft_itoa_size.c \
					libft/ft_itoa_short.c \
					libft/ft_itoa_signed_char.c \
					libft/ft_itoa_ulong_long.c \
					libft/ft_itoa_ulong.c \
					libft/ft_itoa_base_size.c \
					libft/ft_itoa_base_short.c \
					libft/ft_itoa_base_uchar.c \
					libft/ft_uintlen.c \

OBJ				= $(SRC:.c=.o)
CFLAGS			= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33;32mCompilation de la libairie $(NAME)\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[33;32m===> OK <===\033[0m"

%.o: $(SRCDIR)%.c 
	@echo "\033[33;32mCompilation .c > .o\033[0m"
	@gcc $(CFLAGS) -o $@ -c $< -I$(INCDIR)

clean:
	@echo "\033[31mremove printf/*.o\033[0m"
	@rm -f $(OBJ)
	@echo "\033[33;32m===> OK <===\033[0m"

fclean: clean
	@echo "\033[31mremove executable $(NAME)\033[0m"
	@rm -f $(NAME)
	@echo "\033[33;32m===> OK <===\033[0m"

re: fclean all