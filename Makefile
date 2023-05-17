NAME = so_long
LIBFT = libft/libft.a
LIBFT_PATH = libft/
SRC = get_map.c so_long.c validate_file.c validate_map_utils.c validate_map.c utils.c
SRC_BS = pipex_bonus.c process_bonus.c commands_bonus.c 
RM = @rm -f
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g -o pipex -fsanitize=address

OBJ = $(SRC:.c=.o)
BOBJ = $(SRC_BS:.c=.o)

all:			$(NAME)

bonus: 	$(BOBJ)
		@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(BOBJ) -o pipex $(LIBFT)

$(NAME):		$(OBJ)	
				@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
				$(CC) $(CFLAGS) $(OBJ) -o $(@) $(LIBFT) 


clean:
				make clean -C $(LIBFT_PATH)
				$(RM) $(OBJ) $(BOBJ)

fclean: 		clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)

re:		fclean	$(NAME) $(OBJ)

reb:		fclean bonus $(BOBJ)

.PHONY: all clean fclean re bonus