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
#define SIZE 15

class Index{
	int row,col;
	Index(int r, int c):row(r),col(c){}
};

class Matrix{
	public:
		char** matrix;
		int row, col;

		Matrix(int r, int c):row(r),col(c){
			matrix= new char*[row];
			for(int i=0;i<row;++i)
				matrix[i]= new char[col+1];
		}
		Matrix(){};

		friend ostream& operator<<(ostream& os, Matrix& mat){
			for(int i=0;i< mat.row;++i)
				os << mat.matrix[i]<<endl;
			return os;
		}

};

int main(){
	int m,n;
	int i,j,k,l;
	Matrix matrix1(SIZE,SIZE);
	matrix matrix2(SIZE,SIZE); 
	while(scanf("%d%d\n",&m,&n), m||n){
		rep(i,0,r)
			scanf("%s",matrix.matrix[i]);

		cout << matrix <<endl;
	}
}