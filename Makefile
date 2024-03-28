# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 09:02:41 by suhelal           #+#    #+#              #
#    Updated: 2024/03/26 10:41:28 by suhelal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server

SERVER_BONUS = server_bonus

CLIENT_NAME = client

CLIENT_BONUS = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

all: $(CLIENT_NAME) $(SERVER_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_NAME):
	$(CC) $(CFLAGS) client.c minitalk_utils.c check_error_pid.c -o $(CLIENT_NAME)

$(SERVER_NAME):
	$(CC) $(CFLAGS) server.c minitalk_utils.c check_error_pid.c -o $(SERVER_NAME)
	
$(CLIENT_BONUS):
	$(CC) $(CFLAGS) client_bonus.c minitalk_utils.c check_error_pid.c -o $(CLIENT_BONUS)

$(SERVER_BONUS):
	$(CC) $(CFLAGS) server_bonus.c minitalk_utils.c check_error_pid.c -o $(SERVER_BONUS)

clean:
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

re: clean $(CLIENT_NAME) $(SERVER_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)
