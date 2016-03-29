All: Sudoku.o giveQuestion.o transform.cpp
	g++ -o giveQuestion Sudoku.o giveQuestion.cpp
	g++ -o transform Sudoku.o transform.cpp

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o
	
clean:
	rm sudo *.o
