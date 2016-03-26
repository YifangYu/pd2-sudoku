#include<iostream>
#include"sudoku.h"
using namespace std;

int main(){
	Sudo su;
	int map[81];
	su.Map(map);
	su.flip(map,1);	
	su.giveQuestion(map);
	return 0;
}
