NAME		=	so_long

NAME_B		=	so_long_bonus

SRC			=	main.c $(SRC_MAP) $(SRC_CHK) $(SRC_GAME)

SRC_B		=	main_bonus.c $(SRC_MAP) $(SRC_GAME) $(SRC_BONUS)

SRC_CHK		=	$(addprefix checks/, $(CHK))

CHK			=	check_surrounded.c check_contain.c checks.c

SRC_MAP		=	$(addprefix draw_map/, $(MAP))

MAP			=	additional_functions_2.c additional_functions.c draw_map.c \
				ft_split.c open_and_fill_map.c

SRC_GAME	=	$(addprefix game/, $(GAME))

GAME 		=	end_game.c find_player.c player_move.c

SRC_BONUS	=	$(addprefix bonus/, $(BONUS))

BONUS		=	foe_move.c animation.c check_surrounded.c check_contain.c checks.c

OBJ			=	$(SRC:.c=.o)

OBJ_B		=	$(SRC_B:.c=.o)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

MLX			=	-L mlx -lmlx -framework OpenGL -framework AppKit

all:	$(NAME)

bonus:	$(NAME_B)

$(NAME):	$(OBJ)
	make -s -C ./mlx
	$(CC) $(FLAGS) $(OBJ) $(MLX) -o $(NAME)

$(NAME_B):	$(OBJ_B)
	make -s -C ./mlx
	$(CC) $(FLAGS) $(OBJ_B) $(MLX) -o $(NAME_B)

norm:
	norminette *h $(SRC) $(SRC_B)

clean:
	make clean -C ./mlx
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re:		fclean all
	make re -C ./mlx

.PHONY:		bonus all clean fclean re