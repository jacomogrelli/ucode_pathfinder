NAME = pathfinder

INC = pathfinder.h

INCF = inc/pathfinder.h

INC_LIB = ./libmx/libmx.a

SRC = \
main.c \
pf_errorcheck_all.c \
mx_isalpha.c \
pf_uniq_matrix.c

SRCF = \
src/main.c \
src/pf_errorcheck_all.c \
src/mx_isalpha.c \
src/pf_uniq_matrix.c

OBJ = \
main.o \
pf_errorcheck_all.o \
mx_isalpha.o \
pf_uniq_matrix.o

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

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
