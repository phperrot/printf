# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phperrot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 10:58:37 by phperrot          #+#    #+#              #
#    Updated: 2020/02/01 16:37:48 by phperrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = ft_printf.h

NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_parameters.c \
	   ft_printf_read_param.c \
	   ft_printf_read_param2.c \
	   ft_printf_utils.c \
	   ft_printf_utils2.c \
	   ft_printf_width.c \
	   ft_printf_precision.c

INC_LIBFT = libft
CFLAGS = -Wall -Werror -Wextra -MMD -I$(HEADER) -I$(INC_LIBFT)
BUILD_DIR = obj

OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(BUILD_DIR)/,$(OBJS))
DPD = $(OBJ:.o=.d)

opti :
	@make -j all

all : $(NAME)

$(NAME): $(OBJ)
	@make -C libft all
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

$(BUILD_DIR)/%.o: %.c Makefile
	@mkdir -p $(BUILD_DIR)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(BUILD_DIR)
	@echo "Object and DPD files deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Lib deleted"

re : 
	@make fclean
	@make opti

.PHONY: all, clean, fclean, re

-include $(DPD)
