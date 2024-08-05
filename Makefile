# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plang <plang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 13:49:12 by plang             #+#    #+#              #
#    Updated: 2024/08/05 14:49:14 by plang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		= server

CLIENT		= client

B_SERVER	= server_bonus

B_CLIENT	= client_bonus

CC			= @cc

CFLAGS		= -Wall -Werror -Wextra

LIBFT_PATH	= ./libft

LIBFT		= $(LIBFT_PATH)/libft.a

S_SRC		= src/server.c

C_SRC		= src/client.c

S_OBJ		= $(S_SRC:.c=.o)

C_OBJ		= $(C_SRC:.c=.o)

BS_SRC		= ./bonus/src/server_bonus.c

BC_SRC		= ./bonus/src/client_bonus.c

BS_OBJ		= $(BS_SRC:.c=.o)

BC_OBJ		= $(BC_SRC:.c=.o)

all:			$(SERVER) $(CLIENT)

bonus: .bonus

.bonus: 		$(B_SERVER) $(B_CLIENT)
	@touch .bonus

$(LIBFT):
	@make -C	$(LIBFT_PATH)

$(SERVER):		$(LIBFT) $(S_OBJ)
	$(CC)		$(CFLAGS) $(S_OBJ) $(LIBFT) -o $(SERVER)
	@echo "Server compiled!"

$(CLIENT):		$(LIBFT) $(C_OBJ)
	$(CC)		$(CFLAGS) $(C_OBJ) $(LIBFT) -o $(CLIENT)
	@echo "Client compiled!"

$(B_SERVER):	$(LIBFT) $(BS_OBJ)
	$(CC)		$(CFLAGS) $(BS_OBJ) $(LIBFT) -o $(B_SERVER)
	@echo "Bonus Server compiled!"

$(B_CLIENT):	$(LIBFT) $(BC_OBJ)
	$(CC)		$(CFLAGS) $(BC_OBJ) $(LIBFT) -o $(B_CLIENT)
	@echo "Bonus Client compiled!"

clean:
	@rm -f		$(S_OBJ) $(C_OBJ) $(BS_OBJ) $(BC_OBJ)
	@make -C	$(LIBFT_PATH) fclean
	@echo "Removed -o files"
	@rm -f .bonus

fclean:	clean
	@rm -f		$(SERVER) $(CLIENT)
	@rm -f		$(B_SERVER) $(B_CLIENT)
	@echo "Removed all programs!"

re: fclean 		$(SERVER) $(CLIENT)

.PHONY: all clean fclean re libft bonus