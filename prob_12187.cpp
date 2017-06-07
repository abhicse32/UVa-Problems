#include <iostream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define size 105

class Matrix{
	public:
		int** matrix;
		int row,col;

		Matrix(int r, int c):row(r),col(c){
			matrix= new int*[row];
			for(int i=0;i<row;++i)
				matrix[i]= new int[col];
		}
		Matrix():row(0),col(0){};

		friend ostream& operator<<(ostream& os, Matrix& mat){
			int i,j;
			rep(i,0,mat.row){
				os <<mat.matrix[i][0];
				rep(j,1,mat.col)
					os <<" "<< mat.matrix[i][j];
				os <<endl;
			}
			return os;
		}
	void copy(Matrix& matrix2){
		int i,j,k;
		rep(i,0,row){
			rep(j,0,col)
				matrix[i][j]=matrix2.matrix[i][j];
		}
	}
};

int main(int argc, char const *argv[])
{
	int N,R,C,K;
	int i,j,k,l;
	Matrix matrix(size,size);
	Matrix matrix2(size,size);

	while(cin >> N >> R >> C >> K, N){
		matrix.row=matrix2.row= R;
		matrix.col=matrix2.col= C;
		rep(i,0,R){
			rep(j,0,C)
				scanf("%d",&matrix.matrix[i][j]);
		}
		// simulate
		while(K--){
			matrix2.copy(matrix);
			rep(i,0,R){
				rep(j,0,C){
					int attacked= (matrix.matrix[i][j]+1)%N;
					if(i-1>=0 && matrix.matrix[i-1][j]==attacked)
						matrix2.matrix[i-1][j]= matrix.matrix[i][j];
					if(j-1>=0 && matrix.matrix[i][j-1]==attacked)
						matrix2.matrix[i][j-1]= matrix.matrix[i][j];
					if(i+1<R && matrix.matrix[i+1][j]==attacked)
						matrix2.matrix[i+1][j]= matrix.matrix[i][j];
					if(j+1<C && matrix.matrix[i][j+1]==attacked)
						matrix2.matrix[i][j+1]= matrix.matrix[i][j];
				}
			}
			matrix.copy(matrix2);
		}
		cout << matrix;
	}
	return 0;
}