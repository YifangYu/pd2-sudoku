#include<iostream>
#include<vector>
int ProbMapPoint(int *in, int i, int j);
int ProbMap(int *in,int *out);
int ProbNum(int *in, int i, int j);
void ModifiedMap(int *inMap,int *inProMap);
using namespace std;
int main(){
	vector<int> mapin;
	mapin.resize(81);
	for(int i=0;i<81;i++){
	int y;
	cin>>y;
	mapin.at(i)=y;	
	}

	int p[9][9],sudo[9][9];
	//transform 1D to 2D
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			sudo[i][j]=mapin[i*9+j];}}

	int tmp=1;
	for(int i=1;;i++){
		tmp=ProbMap(*sudo,*p);
		ModifiedMap(*sudo,*p);
	if(tmp==0) break;
	}
	//transform 2D to 1D
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			mapin[i*9+j]=sudo[i][j];}}
	
	//check if unsolvable
	for(int i=0;i<81;i++){
		if (mapin[i]==10){
			cout<<"0"<<endl;
			break;}
	}

	//check if more than one answer
	for(int i=0;i<81;i++){
		if (mapin[i]==0){
			cout<<"2"<<endl;
			break;}
	}

	//print the answer
	cout<<"1"<<endl;
	for(int i=0;i<81;i++){
		cout<<mapin[i]<<" ";
		if(i%9==8) cout<<endl;
		}


	return 0;
}
int ProbMapPoint(int *in, int i, int j){
	bool total[9];
	int count=0;
	int v_min,v_max,h_min,h_max;
	if(in[9*i+j]!=0)
		return 0;

	//initial
	for(int k=0;k<9;k++)
		total[k]=true;

	//virtical
	for(int k=0;k<9;k++)
		if(in[9*k+j]!=0)
			total[in[k*9+j]-1]=false;

	//horizontal
	for(int k=0;k<9;k++)
		if(in[9*i+k]!=0)
			total[in[i*9+k]-1]=false;

	//square
	if(i<3){
		v_min=0;v_max=3;
	}else if(i<6){
		v_min=3;v_max=6;
	}else {
		v_min=6;v_max=9;
	}

	if(j<3){
		h_min=0;h_max=3;
	}else if(j<6){
		h_min=3;h_max=6;
	}else{
		h_min=6;h_max=9;
	}

	for(int v=v_min;v<v_max;v++)
		for(int h=h_min;h<h_max;h++)
			if(in[v*9+h]!=0)
				total[in[v*9+h]-1]=false;

	count=0;
	for(int i=0;i<9;i++)
		if(total[i])
			count++;
	return count;
}

int ProbMap(int *in,int *out){
	int tmp=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			out[9*i+j]=ProbMapPoint(in,i,j);
			tmp=(out[9*i+j]==1)?1:tmp;
		}
	}
	return tmp;
}

int ProbNum(int *in, int i, int j){
	bool total[9];
	int v_min,v_max,h_min,h_max;
	if(in[9*i+j]!=0)
		return 0;

	//initial
	for(int k=0;k<9;k++)
		total[k]=true;

	//virtical
	for(int k=0;k<9;k++)
		if(in[9*k+j]!=0)
			total[in[k*9+j]-1]=false;

	//horizontal
	for(int k=0;k<9;k++)
		if(in[9*i+k]!=0)
			total[in[i*9+k]-1]=false;

	//square
	if(i<3){
		v_min=0;v_max=3;
	}else if(i<6){
		v_min=3;v_max=6;
	}else {
		v_min=6;v_max=9;
	}

	if(j<3){
		h_min=0;h_max=3;
	}else if(j<6){
		h_min=3;h_max=6;
	}else{
		h_min=6;h_max=9;
	}

	for(int v=v_min;v<v_max;v++)
		for(int h=h_min;h<h_max;h++)
			if(in[v*9+h]!=0)
				total[in[v*9+h]-1]=false;

	for(int i=0;i<9;i++)
		if(total[i])
			return i+1;
	return 10;

}

void ModifiedMap(int *inMap,int *inProMap){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(inProMap[i*9+j]==1){
				inMap[i*9+j]=ProbNum(inMap,i,j);}
		}
	}
}







