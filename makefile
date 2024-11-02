# Makefile du projet n-reines TP 2 BGL

# Ce fichier gère la compilation du projet ainsi que l'exécution des tests unitaires

# Variables de compilation ( cf : Variable slide 9 )
CC = clang
CFLAGS = -Wall -Wextra -O2 --coverage
LDFLAGS = -L /opt/homebrew/Cellar/cmocka/1.1.7/lib/ -lcmocka --coverage 
INCLUDE = -I /opt/homebrew/Cellar/cmocka/1.1.7/include
# Fichiers objets à générer ( cf : slide 5 )
OBJ = main.o queens.o

# Cible principale pour générer l'exécutable queens ( cf : slide 8 )
all: queens

# Commande pour générer l'exécutable à partir des objets ( cf : slide 5 )
queens: $(OBJ) 
	$(CC) -o queens $(OBJ) $(LDFLAGS)

# Règle implicite pour compiler les fichiers .o à partir des fichiers .c, cette règle générique compile n'importe quel fichier .o à partir du fichier .c correspondant ( cf : slide 11 )
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation séparée des fichiers objets ( cf : slide 6 et 11 )
# Ces règles ne sont plus nécessaires grâce à la règle implicite ci-dessus :
# main.o: main.c queens.h
#	$(CC) $(CFLAGS) -c main.c
# queens.o: queens.c queens.h
#	$(CC) $(CFLAGS) -c queens.c

# Règles de compilation pour les tests unitaires  ( cf : slide 6 )
#test_queens.o: test_queens.c queens.h
#	$(CC) $(CFLAGS) -c test_queens.c $(INCLUDE)

#test_queens: test_queens.o
#	$(CC) -o test_queens test_queens.o $(LDFLAGS) $(INCLUDE)

#test_main.o: test_main.c queens.h
#	$(CC) $(CFLAGS) -c test_main.c $(INCLUDE)

#test_main: test_main.o
#	$(CC) -o test_main test_main.o $(LDFLAGS) $(INCLUDE)

test_queens.o: test_queens.c queens.h
	$(CC) $(CFLAGS) -c test_queens.c $(INCLUDE)

test_main.o: test_main.c queens.h
	$(CC) $(CFLAGS) -c test_main.c $(INCLUDE) 

test_queens: test_queens.o queens.o
	$(CC) -o test_queens test_queens.o queens.o $(LDFLAGS) $(INCLUDE)

test_main: test_main.o queens.o
	$(CC) -o test_main test_main.o queens.o $(LDFLAGS) $(INCLUDE)
		
check: test_queens test_main
	./test_queens
	./test_main
	llvm-cov gcov -f -b test_queens
	llvm-cov gcov -f -b test_main
	
# Cible clean pour nettoyer les fichiers générés ( cf : slide 7 )
clean:
	rm -f *.o queens test_queens test_main *.gcda *.gcno *.gcov

.PHONY: clean all check # Cibles factices