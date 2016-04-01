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
		void rotate(int n);
		int ProbMapPoint(int *in, int i, int j);
		int ProbMap(int *in,int *out);
		int ProbNum(int *in, int i, int j);
		void ModifiedMap(int *inMap,int *inProMap);
	
	private:
		vector<int> mapin;
};
