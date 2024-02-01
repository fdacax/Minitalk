NAME = server client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/

SERVER = server
SERVER_SRCS = server.c
SERVER_OBJ = $(SERVER_SRCS:.c=.o)

CLIENT = client
CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(NAME)
	$(NAME): $(LIBFT) $(SERVER_OBJ) $(CLIENT_OBJ)
		$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)
		@echo "server and client are ready!"
	$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)
	%.o : %.c
		$(CC) &(CFLAGS) -c $< -o $@

	clean:
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

	fclean: clean
		$(RM) $(CLIENT) $(SERVER)
	@echo "server and client have bean cleaned successfully"

	re: fclean
		$(MAKE)