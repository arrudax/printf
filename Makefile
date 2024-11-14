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
SRCS_PRINTF			:= src/bonus/printf/
SRCS_FORMAT			:= src/bonus/format/
SRCS_SPACES			:= $(SRCS_FORMAT)spaces/
SRCS_ZEROS			:= $(SRCS_FORMAT)zeros/
SRCS_PARSE			:= $(SRCS_FORMAT)parse/
SRCS_CMP			:= src/bonus/cmp/
SRCS_HANDLER		:= src/bonus/handler/
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

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_FORMAT), ft_format_string_bonus.c\
	ft_vsprintf_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_ZEROS), ft_format_zero_in_str_bonus.c \
	ft_format_zero_pad_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_SPACES), ft_format_space_in_str_bonus.c)
SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_PARSE), ft_parse_precision_and_width_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_CMP), ft_cmp_and_join_str_space_bonus.c \
	ft_cmp_and_join_str_zero_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_HANDLER), ft_handler_case_bonus.c)

SOURCE_FILES_BONUS	+=$(addprefix $(SRCS_PRINTF), ft_printf_bonus.c)

SOURCE_FILES		+=$(addprefix $(SRCS_FORMAT), ft_vsprintf.c)
 
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
