#include<iostream>
#include"sudoku.h"
using namespace std;
int main()
{
	Sudo ss;
	int map[81];
	ss.Map(map);
	for(int i=0;i<81;i++){
		cout<<map[i]<<" ";
		if(i%9==8)
			cout<<endl;
	}
return 0;
}

