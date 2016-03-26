Sudo: sudoku.o giveQuestion.o
	g++ -o sudo sudoku.o giveQuestion.o

sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp
	
giveQuestion.o: giveQuestion.cpp sudoku.h
	g++ -c giveQuestion.cpp

clean:
	rm sudo *.o
