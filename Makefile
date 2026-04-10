# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 14:53:24 by hcorrea-          #+#    #+#              #
#    Updated: 2023/03/18 19:47:01 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			=	\033[0;32m
RED				=	\033[0;31m
YELLOW			=	\033[0;33m
END				=	\033[0m

SO_LONG			=	so_long

PROJECTDIR		=	src
LIBFT_DIR		=	Libft
INC				=	inc
OBJ_DIR			=	obj
HEADER			=	$(INC)
LIBFT_HEADER	=	$(LIBFT_DIR)/$(INC)/libft.h
LIBFT_LIB		=	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-L./mlx -lmlx -framework OpenGL -framework AppKit

SRC				=	core/main.c			\
					core/init.c			\
					core/end.c			\
					core/free.c			\
					entities/pacman.c	\
					entities/enemy.c	\
					entities/gif.c		\
					entities/collision.c\
					map/map_parsing.c	\
					map/map_validation.c\
					map/map_checks.c	\
					map/pathfinding.c	\
					render/render.c		\
					render/init_imgs.c	\
					utils/mallocs.c		\
					utils/get_next_line.c\

OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_FILE		:=	$(LIBFT_DIR)/$(LIBFT_LIB)

RM				=	rm -rf
MKDIR			=	mkdir -p
MAKE			=	make -C
ERRIGNORE		=	2>/dev/null

all:			 	$(SO_LONG)
					@echo "$(GREEN)So_Long successfully compiled!$(END)"
					@sleep 0.5
					@clear
					
$(SO_LONG):			libft minilibx $(OBJ)
					@clear
					@echo "$(YELLOW)Compiling So_Long...$(END)"
					@$(CC) $(CFLAGS) $(LDFLAGS) -I $(HEADER) -I $(LIBFT_HEADER) $(LIBFT_FILE) $(OBJ) -o $@
					
$(OBJ_DIR)/%.o:		$(PROJECTDIR)/%.c $(HEADER)
					@$(MKDIR) $(dir $@)
					@$(CC) $(CFLAGS) -I $(HEADER) -I $(LIBFT_HEADER) -o $@ -c $<

%.o:				%.c
					@$(CC) $(CFLAGS) -I $(HEADER) -I $(LIBFT_HEADER) -Imlx -c $< -o $@

minilibx:
					@echo "$(YELLOW)Compiling Minilibx...$(END)"
					@$(MAKE) mlx > /dev/null 2>&1
					@echo "$(GREEN)Minilibx successfully compiled!$(END)"
					@sleep 0.5
					@clear

libft:				$(LIBFT_FILE)

$(LIBFT_FILE):
					@$(MAKE) $(LIBFT_DIR)
					@sleep 0.5
					@clear

clean:
					@$(RM) $(OBJ_DIR)
					@$(MAKE) mlx clean > /dev/null 2>&1
					@$(MAKE) $(LIBFT_DIR) clean
					@clear
					@echo "$(RED)All objects deleted!$(END)"

fclean:				clean
					@$(RM) $(SO_LONG)
					@$(MAKE) $(LIBFT_DIR) fclean
					@echo "$(RED)All executables deleted!$(END)"
					@sleep 0.5
					@clear

re:					fclean all

.PHONY:				all clean fclean re libft minilibx
					
re:					fclean all

.PHONY:	clean, fclean, re, minilibx