#include<iostream>
#include <stdlib.h>
#include <time.h>
#include"sudoku.h"
using namespace std;

void Sudo::Map(int mapin[]){
int map[81]={2,8,3,1,4,5,7,6,9,
9,6,4,2,7,3,1,5,8,
7,1,5,6,8,9,2,4,3,
3,5,8,4,2,1,9,7,6,
4,2,7,9,5,6,8,3,1,
1,9,6,7,3,8,4,2,5,
8,4,9,3,6,7,5,1,2,
6,7,1,5,9,2,3,8,4,
5,3,2,8,1,4,6,9,7};
for(int i=0;i<81;i++)
	mapin[i]=map[i];
}

void Sudo::reanIn(){

}

void Sudo::giveQuestion(int mapin[]){
	srand(time(NULL));
	for(int i=0;i<81;i++){
		int random_num=rand()%10;
		if(mapin[i]==random_num) mapin[i]=0;
		if(mapin[i]==random_num+1) mapin[i]=0;
		if(mapin[i]==random_num-1) mapin[i]=0;
	}
	for(int i=0;i<81;i++){
		cout<<mapin[i]<<" ";
		if(i%9==8) cout<<endl;
	}
}

void Sudo::transform(int mapin[]){
	srand(time(NULL));
	int num=rand()%5;
	if (num==1)		 flip(mapin,num);
	else if (num==2) changeCol(mapin);
	else if (num==3) changeRow(mapin);
	else if (num==4) changeNum(mapin); 
	else if (num==0) flip(mapin,num);
}

void Sudo::changeNum(int mapin[]){
	for(int i=0;i<81;++i){
		if(mapin[i]==5) mapin[i]=mapin[i]+2;
		else if(mapin[i]==7) mapin[i]=mapin[i]-2;
	}
}

void Sudo::changeRow(int mapin[]){
	int tmp;
	for(int i=27;i<54;i++){
		tmp=mapin[i];
		mapin[i]=mapin[i+27];
		mapin[i+27]=tmp;
	}
}

void Sudo::changeCol(int mapin[]){
	int tmp;
	for(int i=0;i<75;i+=9){
		for(int j=0;j<3;j++){
			tmp=mapin[i+j];
			mapin[i+j]=mapin[i+j+6];
			mapin[i+j+6]=tmp;
		}
	}
}

void Sudo::flip(int mapin[],int i){
	int tmp;
	if(i==0){
	for(int i=0;i<9;i++){
		tmp=mapin[i];
		mapin[i]=mapin[i+72];
		mapin[i+72]=tmp;}
	for(int i=9;i<18;i++){
		tmp=mapin[i];
		mapin[i]=mapin[i+54];
		mapin[i+54]=tmp;}
	for(int i=18;i<27;i++){
		tmp=mapin[i];
		mapin[i]=mapin[i+36];
		mapin[i+36]=tmp;}
	for(int i=27;i<36;i++){
		tmp=mapin[i];
		mapin[i]=mapin[i+18];
		mapin[i+18]=tmp;}
}
	else {
	for(int i=0;i<81;i+=9){
		tmp=mapin[i];
		mapin[i]=mapin[i+8];
		mapin[i+8]=tmp;}
	for(int i=1;i<81;i+=9){
		tmp=mapin[i];
		mapin[i]=mapin[i+6];
		mapin[i+6]=tmp;}
	for(int i=2;i<81;i+=9){
		tmp=mapin[i];
		mapin[i]=mapin[i+4];
		mapin[i+4]=tmp;}
	for(int i=3;i<81;i+=9){
		tmp=mapin[i];
		mapin[i]=mapin[i+2];
		mapin[i+2]=tmp;}
}
}
