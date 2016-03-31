All: Sudoku.o giveQuestion.o transform.cpp solve.cpp
	g++ -o giveQuestion Sudoku.o giveQuestion.cpp
	g++ -o transform Sudoku.o transform.cpp
	g++ -o solve Sudoku.o solve.cpp
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o
	
clean:
	rm sudo *.o
