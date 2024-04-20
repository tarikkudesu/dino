SRC		=	dino.c \
			error.c \
			key_hook.c

GREEN		=	'\033[32m'
NONE		=	'\033[0m'
CC			=	cc
NAME		=	dino
HEADER		=	dino.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L /usr/local/lib -l mlx -framework OpenGL -framework AppKit
LIBT		=	/Users/tamehri/local/ta_lib/libt.a

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) $(LIBT)
	@echo $(GREEN) "compilation done\n" $(NONE)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) "... Compiling\t$<\t[OK]" $(RESET)

clean:
	@rm -f $(OBJ)
	@echo $(GREEN) "clean done\n" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN) "fclean done\n" $(NONE)

re: fclean all
	@echo $(GREEN) "re done\n" $(NONE)

.PHONY: clean

