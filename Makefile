SERVER = server
CLIENT = client

PRINTF = ft_printf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

all:
	@make -s -C $(PRINTF)
	@gcc $(CFLAGS) server.c -o $(SERVER)
	@gcc $(CFLAGS) client.c -o $(CLIENT)
	@echo "server and client are ready!"

	clean:
	@make clean -s -C $(PRINTF)

	fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "server and client have bean cleaned successfully"

	re: fclean all