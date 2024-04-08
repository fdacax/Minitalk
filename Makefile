NAME = server client
NAME_BONUS = server_bonus client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/

SERVER = server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_BONUS = server_bonus
SERVER_SRCS_BONUS = server_bonus.c
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)

CLIENT = client
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_BONUS = client_bonus
CLIENT_SRCS_BONUS = client_bonus.c
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)
	@echo "server and client are ready!"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	$(CC) $(FLAGS) -o $(SERVER_BONUS) $(SERVER_OBJS_BONUS) $(LIBFT)
	$(CC) $(FLAGS) -o $(CLIENT_BONUS) $(CLIENT_OBJS_BONUS) $(LIBFT)
	@echo "Compilation Bonus successful."

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	$(RM) $(LIBFT)
	@echo "server and client have been cleaned successfully"

re: fclean all


.SILENT:

.PHONY: all clean fclean re