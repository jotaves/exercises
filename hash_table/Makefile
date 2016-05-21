one:
	g++ -Wall -std=c++11 src/pgm_ht.cpp -I include/ -o bin/pgm_ht -D TYPE1
two:
	g++ -Wall -std=c++11 src/pgm_ht.cpp -I include/ -o bin/pgm_ht -D TYPE2
run:
	./bin/pgm_ht
clean:
	rm bin/drive
mleak:
	valgrind --tool=memcheck --leak-check=yes ./bin/pgm_ht 
mlfull:
	valgrind --leak-check=full --show-leak-kinds=all ./bin/pgm_ht 