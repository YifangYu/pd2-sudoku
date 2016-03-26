#include<iostream>
#include"sudoku.h"
using namespace std;

int main(){
	Sudo su;
	int map[81];
	su.Map(map);
	su.flip(map,1);	
	for (int i=0;i<81;i++)
		{cout<<map[i]<<" ";
		if(i%9==8) cout<<endl;}
	return 0;
}
