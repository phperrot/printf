# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phperrot <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 15:50:08 by phperrot          #+#    #+#              #
#    Updated: 2020/01/31 09:49:03 by phperrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strlen.c \
	   ft_isdigit.c \
	   ft_strchr.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_atoi.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_itoa.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_putstr.c \
	   ft_strdup_free.c \
	   ft_strncmp.c
INC = libft.h
CFLAGS = -Wall -Werror -Wextra -MMD
BUILD_DIR = obj
OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(BUILD_DIR)/,$(OBJS))
DPD = $(OBJ:.o=.d)

opti :
	@make -j all

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"
	
$(BUILD_DIR)/%.o: %.c Makefile
	@mkdir -p $(BUILD_DIR)
	@gcc $(CFLAGS) -I $(INC) -c $< -o $@

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
