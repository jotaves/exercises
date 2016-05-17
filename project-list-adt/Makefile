drive:
	g++ -Wall -std=c++11 src/drive.cpp -o bin/drive -I include/
run:
	./bin/drive
clean:
	rm bin/drive
mleak:
	valgrind --tool=memcheck ./bin/drive