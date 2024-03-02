# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:11:35 by vboulang          #+#    #+#              #
#    Updated: 2024/03/02 11:12:34 by vboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program names
NAME		=	fdf

#Compiling variables
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address

#Directories
LIBDIR		=	libft
SRCDIR		=	src
INCDIR		=	inc
OBJDIR		=	obj

#Library names
LIBFT		=	$(LIBDIR)/libft.a

#.h files name
INC			=	$(INCDIR)/fdf.h

#Command lines
RM			=	rm -rf
MK			=	mkdir -p

#Source files

SRC			= 	main.c \
				load_map.c \
				hooks.c \
				math.c \
				utils.c \
				free_utils.c \
				hook_loop.c \
				misc_utils.c
#seb.c

VPATH		=	$(SRCDIR)

#Object files
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))

#MLX
MLXFLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/homebrew/opt/glfw/lib/" #Place line if brew42 or not 42
MLXDIR		=	MLX42
MLX			=	$(MLXDIR)/build/libmlx42.a
MLXINC		=	$(MLXDIR)/include

all:  libmlx $(NAME) #deps

$(NAME):	$(OBJDIR) $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJDIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/inc -c $< -o $@

$(OBJDIR):
	$(MK) $(OBJDIR)

# deps:
	@if [ ! -f /Users/$(USER)/.brew/bin/brew ]; then \
		yes | -/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"; \
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

clean:
	$(RM) $(OBJDIR)
	$(RM) $(MLXDIR)/build
	make -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
