NAME = pathfinder

INC = pathfinder.h

INCF = inc/pathfinder.h

INC_LIB = ./libmx/libmx.a

SRC = \
main.c \
mx_pf_errorcheck_all.c \
mx_pf_uniq_matrix.c \
mx_pf_matrix_init.c \
mx_pf_error_line_check.c

SRCF = \
src/main.c \
src/mx_pf_errorcheck_all.c \
src/mx_pf_uniq_matrix.c \
src/mx_pf_matrix_init.c \
src/mx_pf_error_line_check.c

OBJ = \
main.o \
mx_pf_errorcheck_all.o \
mx_pf_uniq_matrix.o \
mx_pf_matrix_init.o \
mx_pf_error_line_check.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

all: install clean

install:
	@cd libmx && make reinstall
	@cp $(SRCF) $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(INC_LIB) $(OBJ) -o $(NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj
	@rm -rf $(SRC) $(INC)

uninstall:
	@rm -rf $(NAME) $(INC_LIB) ./obj

clean:
	@rm -rf ./obj
	@rm -rf $(OBJ) $(SRC) $(INC)

reinstall: uninstall all

test:
	@cp $(SRCF) $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(INC_LIB) $(OBJ) -o $(NAME) -g
	@mkdir -p ./obj
	@mv $(OBJ) ./obj
	@rm -rf $(SRC) $(INC)

git:
	@git add .
	@git commit -m "-"
	@git push
