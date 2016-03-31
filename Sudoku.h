#include<iostream>
#include<vector>
using namespace std;
class Sudoku{
	public:
		Sudoku();
		void readIn();
		void giveQuestion();
		void transform();
		void changeNum();
		void changeRow();
		void changeCol();
		void flip(int i);
		void solve();
	private:
		vector<int> mapin;
};
