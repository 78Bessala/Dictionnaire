exo1: Fonction_bessala.c Fonction_bessala.h main_bessala.c
	gcc -o exo1 Fonction_bessala.c main_bessala.c -g -O0 -lm -lpthread -fopenmp 

run:exo1
	./exo1 
run_valgrind:exo1
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./exo1
clean:
	rm  exo1

profile:
	gcc -Wall -pg Fonction_bessala.c main_bessala.c -lm -lpthread -o exo1