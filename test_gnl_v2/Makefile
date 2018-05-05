CC = clang
CC_FLAGS = -Wall -Werror -Wextra

# Chnge PROJ_DIR to the directory of your project

PROJ_NAME = get_next_line
PROJ_DIR = ~/gnl_test/
LIB_DIR = $(PROJ_DIR)libft/
LIB_INC_DIR = $(LIB_DIR)includes/

TMP_DIR = ./.tmp_dir/

SRC = ./src/return_test_main.c ./src/main.c ./src/multiple_fd_test_main.c $(PROJ_DIR)get_next_line.c
OBJ1 = main.o
OBJ2 = return_test_main.o
OBJ3 = get_next_line.o
OBJ4 = multiple_fd_test_main.o

all: lib head $(OBJ3) test_gnl return_test_gnl multiple_fd_test

test_gnl: $(OBJ1)
	$(CC) -o test_gnl $(OBJ1) $(OBJ3) -I $(LIB_INC_DIR) -L $(LIB_DIR) -lft

return_test_gnl: $(OBJ2)
	$(CC) -o return_test_gnl $(OBJ2) $(OBJ3) -I $(LIB_INC_DIR) -L $(LIB_DIR) -lft

multiple_fd_test: $(OBJ4)
	$(CC) -o multiple_fd_test $(OBJ4) $(OBJ3) -I $(LIB_INC_DIR) -L $(LIB_DIR) -lft

lib:
	@make -C $(LIB_DIR)

$(TMP_DIR):
	mkdir $(TMP_DIR)

head: $(TMP_DIR)
	cp $(PROJ_DIR)$(PROJ_NAME).h $(TMP_DIR)$(PROJ_NAME).h

main.o: ./src/main.c
	$(CC) -c $< -o $@ $(CC_FLAGS) -I $(PROJ_DIR)

return_test_main.o: ./src/return_test_main.c
	$(CC) -c $< -o $@ $(CC_FLAGS) -I $(PROJ_DIR)

multiple_fd_test_main.o: ./src/multiple_fd_test_main.c
	$(CC) -c $< -o $@ $(CC_FLAGS) -I $(PROJ_DIR)

get_next_line.o: $(PROJ_DIR)get_next_line.c
	$(CC) -c $< -o $@ $(CC_FLAGS) -I $(PROJ_DIR) -I $(LIB_INC_DIR)

norm: fclean
	norminette $(PROJ_DIR)

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f $(OBJ3)
	rm -f $(OBJ4)
	rm -rf $(TMP_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f test_gnl
	rm -f return_test_gnl
	make -C $(LIB_DIR) fclean

re: fclean all
