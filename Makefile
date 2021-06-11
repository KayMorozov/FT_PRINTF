NAME = libftprintf.a

PRINTF_HEADER = ft_printf.h

LIBFT_HEADER = libft/libft.h

PRINTF_SRC = ft_printf.c\
	  src/flag_init.c\
	  src/add_flags.c\
	  src/check_flag_types.c\
	  src/ft_minus.c\
	  src/ft_space.c\
	  src/ft_zero.c\
	  src/ft_dot.c\
	  src/ft_prescision.c\
	  src/ft_width.c\
	  src/ft_print_decimal.c\
	  src/flag_to_string.c\
	  src/ft_change_flags.c\
	  src/ft_print.c\
	  src/ft_print_unsigned.c\
	  src/ft_print_string.c\
	  src/ft_print_char.c\
	  src/ft_print_pointer.c\
	  src/ft_print_hex.c\
	  src/ft_print_percent.c\

LIBFT_SRC = libft/ft_memset.c\
            	  libft/ft_bzero.c\
            	  libft/ft_memcpy.c\
            	  libft/ft_memccpy.c\
            	  libft/ft_memmove.c\
            	  libft/ft_memchr.c\
            	  libft/ft_memcmp.c\
            	  libft/ft_strlen.c\
            	  libft/ft_strlcpy.c\
            	  libft/ft_strlcat.c\
            	  libft/ft_strchr.c\
            	  libft/ft_strrchr.c\
            	  libft/ft_strnstr.c\
            	  libft/ft_strncmp.c\
            	  libft/ft_atoil.c\
            	  libft/ft_isalpha.c\
            	  libft/ft_isdigit.c\
            	  libft/ft_isalnum.c\
            	  libft/ft_isascii.c\
            	  libft/ft_isprint.c\
            	  libft/ft_toupper.c\
            	  libft/ft_tolower.c\
            	  libft/ft_calloc.c\
            	  libft/ft_strdup.c\
            	  libft/ft_substr.c\
            	  libft/ft_strjoin.c\
            	  libft/ft_strtrim.c\
            	  libft/ft_split.c\
            	  libft/ft_itoa.c\
            	  libft/ft_strmapi.c\
            	  libft/ft_putchar_fd.c\
            	  libft/ft_putstr_fd.c\
            	  libft/ft_putendl_fd.c\
            	  libft/ft_putnbr_fd.c\
            	  libft/ft_itoa_flags.c\
            	  libft/ft_utoa_flags.c\

OBJS += $(PRINTF_SRC:.c=.o)
OBJS += $(LIBFT_SRC:.c=.o)

CC = gcc
CFLAGS = -Wextra -Werror -Wall -I.
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_HEADER) $(LIBFT_HEADER)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
