#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked
int len=0;

void read(char str[]){
	len=0;
	char ch;
	while(true){
		ch= gc();
		if(ch==EOF){
			exit(0);
		}else if(ch=='\n'){
			str[len]='\0';
			break;
		}else str[len++]=ch;
	}
}

class Matrix{
public:
	int size;
	int** matrix;
	Matrix(int sz):size(sz){
		matrix= new int*[size];
		int i;
		rep(i,0,size)
			matrix[i]= new int[size];
	}

	friend ostream& operator<<(ostream& os, Matrix& mat){
		int i,j;
		rep(i,0,mat.size){
			os<< mat.matrix[i][0];
			rep(j,1,mat.size)
				os<<" " << mat.matrix[i][j];
			os << endl;
		}
		return os;
	}
	void reset(){
		int i,j;
		rep(i,0,size)
			memset(matrix[i],0,sizeof(int)*size);
	}
};

void increment(int row, int col, Matrix& mat){
	mat.matrix[row][col]=(mat.matrix[row][col]+1)%10;
	if(row+1<3)
		mat.matrix[row+1][col]=(mat.matrix[row+1][col]+1)%10;
	if(col+1 < 3)
		mat.matrix[row][col+1]=(mat.matrix[row][col+1]+1)%10;
	if(row-1 >=0)
		mat.matrix[row-1][col]= (mat.matrix[row-1][col]+1)%10;
	if(col-1>=0)
		mat.matrix[row][col-1]= (mat.matrix[row][col-1]+1)%10;
}

int main(){
	Matrix matrix(3);
	char str[105];
	int i,j,k;
	for(j=1;;++j){
		matrix.reset();
		read(str);
		rep(i,0,len){
			switch(str[i]){
				case 'a': increment(0,0,matrix); break;
				case 'b': increment(0,1,matrix); break;
				case 'c': increment(0,2,matrix); break;
				case 'd': increment(1,0,matrix); break;
				case 'e': increment(1,1,matrix); break;
				case 'f': increment(1,2,matrix); break;
				case 'g': increment(2,0,matrix); break;
				case 'h': increment(2,1,matrix); break;
				case 'i': increment(2,2,matrix); break;
				default: break;
			}
		}
		printf("Case #%d:\n",j);
		cout <<matrix;
	}
}