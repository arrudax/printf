# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 05:19:48 by maanton2          #+#    #+#              #
#    Updated: 2024/11/14 05:54:26 by maanton2         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

LIBFT_VERSION		:= 2.2.0
 
# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #
 
SRCS_LIBFT			:= libft/
SRCS_LIBFT_FILE		:= $(SRCS_LIBFT)libft.a
SRCS_MANDATORY		:= src/mandatory/
SRCS_PRINTF_BONUS	:= src/bonus/printf/
SRCS_FORMAT_BONUS	:= src/bonus/format/
SRCS_SPACES_BONUS	:= $(SRCS_FORMAT_BONUS)spaces/
SRCS_ZEROS_BONUS	:= $(SRCS_FORMAT_BONUS)zeros/
SRCS_PARSE_BONUS	:= $(SRCS_FORMAT_BONUS)parse/
SRCS_CMP_BONUS		:= src/bonus/cmp/
SRCS_HANLER_BONUS	:= src/bonus/handler/
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

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_FORMAT_BONUS), ft_format_string_bonus.c\
	ft_vsprintf_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_ZEROS_BONUS), ft_format_zero_in_str_bonus.c \
	ft_format_zero_pad_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_SPACES_BONUS), ft_format_space_in_str_bonus.c)
SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_PARSE_BONUS), ft_parse_precision_and_width_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_CMP_BONUS), ft_cmp_and_join_str_space_bonus.c \
	ft_cmp_and_join_str_zero_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_HANLER_BONUS), ft_handler_case_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_PRINTF_BONUS), ft_printf_bonus.c)

SOURCE_FILES		+=$(addprefix $(SRCS_MANDATORY), ft_vsprintf.c ft_printf.c ft_long_to_hex.c ft_int_to_hex.c)
 
OBJECT_FILES		:= $(SOURCE_FILES:%.c=$(BUILD_DIR)%.o)

OBJECT_FILES_BONUS	:= $(SOURCE_FILES_BONUS:%.c=$(BUILD_DIR)%.o)
 
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
	$(RM) $(OBJECT_FILES) $(OBJECT_FILES_BONUS)
endef
 
define fclean
	$(RM) $(NAME)
	$(RM) $(BUILD_DIR)
endef
 
#******************************************************************************#
#                                   RULES                                      #
#******************************************************************************#
 
all: $(NAME)
 
$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)
 
$(NAME): $(SRCS_LIBFT_FILE) | $(OBJECT_FILES) 
	$(AR) $(NAME) $(OBJECT_FILES)
	@echo "Compilação concluída: $(NAME)"
 
$(SRCS_LIBFT_FILE):
	$(call submodule_update_libft)
 
bonus: $(SRCS_LIBFT_FILE) | $(OBJECT_FILES_BONUS)
	$(AR) $(NAME) $(OBJECT_FILES_BONUS)
	@echo "Compilação concluída: $(NAME)"

clean:
	$(call clean)
 
fclean: clean
	$(call fclean)
 
re: fclean all
 
.PHONY: all clean fclean re
