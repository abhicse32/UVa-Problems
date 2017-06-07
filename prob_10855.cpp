#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(i=a;i<b;++i)
#define repb(i,a,b) for(i=b;i>a;--i)

class Matrix{
	public:
		char** matrix;
		int size;

		Matrix(int sz):size(sz){
			matrix= new char*[size];
			for(int i=0;i<size;++i)
				matrix[i]= new char[size+1];
		}
		Matrix(){};

		friend ostream& operator<<(ostream& os, Matrix& mat){
			for(int i=0;i< mat.size;++i)
				os << mat.matrix[i]<<endl;
			return os;
		}

		Matrix& rotate_90_degrees(){
			int half= (size>>1);
			int size2=size;
			for(int i=0;i<half;++i,--size2){
				for(int j=i;j<size2-1;++j){
					int temp= matrix[i][j];
					matrix[i][j]= matrix[size-j-1][i];
					matrix[size-j-1][i]= matrix[size-i-1][size-j-1];
					matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
					matrix[j][size-i-1]= temp;
				}
			}
			return (*this);
		}

		bool found(Matrix& mat, int row, int col){
			for(int i=0,k= row;i<mat.size;++i,++k){
				for(int j=0,l=col;j<mat.size;++j,++l)
					if(matrix[k][l]!=mat.matrix[i][j])
						return false;
			}
			return true;
		}

		int get_count(Matrix& mat){
			int count=0,i,j;
			repf(i,0,size-mat.size+1){
				repf(j,0,size-mat.size+1)
					if(found(mat,i,j))
						++count;
			}
			return count;
		}

};

int main(){

	Matrix matrix1, matrix2, matrix3;
	string str;
	int N,n,i,j,k;
	while(scanf("%d%d\n",&N,&n) && N){
		matrix1= Matrix(N);
		matrix2= Matrix(n);

		repf(i,0,N)
			cin >> str,
			strcpy(matrix1.matrix[i],str.c_str());
		repf(i,0,n)
			cin >>str,
			strcpy(matrix2.matrix[i],str.c_str());

		cout << matrix1.get_count(matrix2)<<" ";
		matrix2.rotate_90_degrees();
		cout << matrix1.get_count(matrix2) <<" ";
		matrix2.rotate_90_degrees();
		cout << matrix1.get_count(matrix2) <<" ";
		matrix2.rotate_90_degrees();
		cout << matrix1.get_count(matrix2)<<endl;
	}

}

