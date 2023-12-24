SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
INC=$(wildcard *.h)

# Name of my static library 
LIB=libbattleship.a

# Target for creating the library
# Exclude main.o if this is the file containing your main function
lib: $(filter-out main.o, $(OBJ))
	ar rcs $(LIB) $^

all: BattleShipDelMondo lib

%.o : %.c $(INC)
	gcc -c $< -o $@

BattleShipDelMondo: $(OBJ)
	gcc -fsanitize=address $^ -o $@

clean:
	rm -f *.o
	rm -f BattleShipDelMondo
	rm -f $(LIB)

