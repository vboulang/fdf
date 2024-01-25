# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:11:35 by vboulang          #+#    #+#              #
#    Updated: 2024/01/25 14:01:00 by vboulang         ###   ########.fr        #
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
				parsing.c \
				hooks.c

VPATH		=	$(SRCDIR)

#Object files
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))

#MLX
MLXFLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" 
MLXDIR		=	MLX42
MLX			=	$(MLXDIR)/build/libmlx42.a
MLXINC		=	$(MLXDIR)/include

all: libmlx $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJDIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/inc -c $< -o $@

$(OBJDIR):
	$(MK) $(OBJDIR)

libmlx:
	cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

clean:
	$(RM) $(OBJDIR)
	$(RM) $(MLXDIR)/build
	make -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
