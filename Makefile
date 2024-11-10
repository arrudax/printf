# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 05:19:48 by maanton2          #+#    #+#              #
#    Updated: 2024/11/10 08:44:04 by maanton2         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #

SRCS_LIBFT			:= libft
SRCS_LIBFT_FILE		:= libft/libft.a
SRCS_PRINTF			:= src/printf/
INCS				:= includes/
BUILD_DIR			:= build/

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM					:= rm -rf
MKDIR				:= mkdir -p
MAKE				:= make
C					:= -C
L-CLEAN				:= $(MAKE) clean $(C)
L-FCLEAN			:= $(MAKE) fclean $(C)

# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #

NAME				:= libftprintf.a

SOURCE_FILES		+=$(addprefix $(SRCS_PRINTF), ft_printf.c)
#	ft_itoa.c \
#	ft_tolower.c \
#	ft_toupper.c)

OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(BUILD_DIR)%.o)

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                 := cc
CFLAGS             := -Wall -Werror -Wextra
CPPFLAGS           := $(addprefix -I, $(INCS))
AR                 := ar -rcs
COMP_OBJS          = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_LIB           = $(AR) $(NAME) $(OBJECT_FILES) $(SRCS_LIBFT_FILE)

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(COMP_OBJS)
endef

define comp_lib
	@$(COMP_LIB)
endef

define clean
	$(RM) $(BUILD_DIR)
endef

define fclean
	$(RM) $(NAME)
endef

define comp_libft
	$(MAKE) $(C) $(SRCS_LIBFT)
endef

define clean_libft
	$(L-CLEAN) $(SRCS_LIBFT)
endef

define fclean_libft
	$(L-FCLEAN) $(SRCS_LIBFT)
endef

#******************************************************************************#
#                                   RULES                                      #
#******************************************************************************#

all: $(NAME) 

$(SRCS_LIBFT_FILE):
	$(call comp_libft)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJECT_FILES) $(SRCS_LIBFT_FILE)
	$(call comp_lib)
	@echo "Compilação concluída: $(NAME)"

clean:
	$(call clean)
	$(call clean_libft)

fclean: clean
	$(call fclean)
	$(call fclean_libft)

re: fclean all

.PHONY: all clean fclean re
