# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:11:35 by vboulang          #+#    #+#              #
#    Updated: 2024/03/14 18:50:29 by vboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program names
NAME		=	fdf
NAME_BONUS	=	fdf_bonus

#Compiling variables
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address

#Directories
LIBDIR			=	libft
SRCDIR			=	src
INCDIR			=	inc
OBJDIR			=	obj
SRCDIR_BONUS	=	bonus

#Library names
LIBFT		=	$(LIBDIR)/libft.a

#.h files name
INC			=	$(INCDIR)/fdf.h
INC_BONUS	=	$(INCDIR)/fdf_bonus.h

#Command lines
RM			=	rm -rf
MK			=	mkdir -p

#Source files

SRC			= 	fdf.c \
				load_map.c \
				hooks.c \
				math.c \
				utils.c \
				free_utils.c \
				misc_utils.c

SRC_BONUS	= 	fdf_bonus.c \
				load_map_bonus.c \
				hooks_bonus.c \
				math_bonus.c \
				utils_bonus.c \
				free_utils_bonus.c \
				hook_loop_bonus.c \
				misc_utils_bonus.c

VPATH		=	$(SRCDIR) $(SRCDIR_BONUS)

#Object files
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))
OBJ_BONUS	=	$(addprefix $(OBJDIR)/,$(SRC_BONUS:%.c=%.o))

#MLX
MLXFLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -pthread -lm -L$(shell brew --prefix glfw)/lib
MLXDIR		=	MLX42
MLX			=	$(MLXDIR)/build/libmlx42.a
MLXINC		=	$(MLXDIR)/include

all: deps libmlx $(NAME) 

$(NAME):	$(OBJDIR) $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(BREWFLAG) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJDIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/inc -c $< -o $@

$(OBJDIR):
	$(MK) $(OBJDIR)

deps:
	@if [ ! -f /Users/$(USER)/.brew/bin/brew ]; then \
		yes | -/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh | zsh)"; \
	fi
	@if ! brew list | grep -q "cmake"; then \
		brew install cmake; \
	fi
	@if ! brew list | grep -q "glfw"; then \
		brew install glfw; \
	fi

libmlx:
	@if [ ! -d "MLX42/build" ]; then \
		cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4; \
	fi

bonus: deps libmlx $(NAME_BONUS)

$(NAME_BONUS):  $(OBJDIR) $(OBJ_BONUS)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(BREWFLAG) $(OBJ_BONUS) $(LIBFT) $(MLX) -o $(NAME_BONUS)

$(OBJDIR)/%.o: %.c $(INC_BONUS)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/inc -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(RM) $(MLXDIR)/build
	make -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx bonus
