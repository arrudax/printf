# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 05:19:48 by maanton2          #+#    #+#              #
#    Updated: 2024/11/12 02:58:43 by maanton2         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

LIBFT_VERSION		:= 2.1.0

# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #

SRCS_LIBFT			:= libft/
SRCS_LIBFT_FILE		:= $(SRCS_LIBFT)libft.a
SRCS_PRINTF			:= src/printf/
INCS				:= includes/ libft/includes
BUILD_DIR			:= build/

#******************************************************************************#
#                               BASH COMMANDS                                  #
#******************************************************************************#

RM					:= rm -rf
MKDIR				:= mkdir -p

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

CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra
CPPFLAGS			:= $(addprefix -I, $(INCS))
AR					:= ar -rcs
COMP_OBJS			= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
LDLIBS				:= -lft -ldl
COMP_LIB			= $(AR) $(NAME) $(OBJECT_FILES) $(LDLIBS)

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define submodule_update_libft
	git submodule update --init --remote >/dev/null 2>&1 || true
	git submodule foreach -q \
		'branch="$(git config -f $toplevel/.gitmodules submodule.Libft)"; \
		git pull origin main; \
		git fetch; \
		git checkout v$(LIBFT_VERSION)' \
		>/dev/null 2>&1 || true
	$(SLEEP)
	$(MAKE) -C $(SRCS_LIBFT)
endef

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
	$(RM) $(OBJECT_FILES)
endef

define fclean
	$(RM) $(NAME)
endef

#******************************************************************************#
#                                   RULES                                      #
#******************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(SRCS_LIBFT_FILE) | $(OBJECT_FILES) 
	$(AR) $(SRCS_LIBFT_FILE) $(NAME) $(OBJECT_FILES)
	@echo "Compilação concluída: $(NAME)"

$(SRCS_LIBFT_FILE):
	$(call submodule_update_libft)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

.PHONY: all clean fclean re
