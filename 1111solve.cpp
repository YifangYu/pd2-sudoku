#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(){
	int location=0,sum=0,b;
	int c[9];
	int *p = &location;
	int map[81]={8,6,5,3,2,9,4,1,7,
		2,4,3,1,7,5,8,6,9,
		1,9,7,6,8,4,5,2,3,
		3,1,9,2,5,8,6,7,4,
		4,2,6,7,9,1,3,5,8,
		5,7,8,4,3,6,1,9,2,
		7,5,4,9,1,3,2,8,6,
		6,8,2,5,4,7,9,3,1,
		9,3,1,8,6,2,7,4,5};	
	//check row
	for(int i=0;i<81;i+=9)
	{
		for(int j=0;j<9;j++)
		{
			c[j]=map[i+j];
			sum=sum+c[j];
		}
		if(sum==45){
		sum=sum-45;}
		else cout<<"error"<<endl;
	}
	
	//check column
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			c[j]=map[i+9*j];
			sum=sum+c[j];
		}
		if(sum==45){
		sum=sum-45;}
		else cout<<"error"<<endl;
	}
	//check cell
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{	
			location=27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
			b = *p;
			c[j]=map[b];
			sum=sum+c[j];
		}
		if(sum==45){
		sum=sum-45;}
		else cout<<"error"<<endl;		
	}
	return 0;
}
