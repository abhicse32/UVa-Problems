#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

class Matrix{
public:
	int size;
	long long** matrix;
	Matrix(int sz):size(sz){
		matrix= new long long*[size];
		for(int i=0;i<size;++i)
			matrix[i]= new long long[size];
	}

	friend ostream& operator<<(ostream& os, Matrix& mat){
		for(int i=0;i< mat.size;++i){
			os<< mat.matrix[i][0];
			for(int j=1;j<mat.size; ++j)
				os<<" " << mat.matrix[i][j];
			os<<endl;
		}
		return os;
	}

	bool isSymmetric(){
		int half= size>>1;
		for(int i=0;i<half;++i){
			for(int j=i;j<size-i;++j){
				if(matrix[i][j]!= matrix[size-i-1][size-j-1] ||
					matrix[j][size-i-1] != matrix[size-j-1][i])
					return false;
			}
		}
		
		return true;
	}

};

int main(){
	int n,i,j,k,size;
	scanf("%d",&n);
	char ch1, ch2;
	for(i=1;i<=n;++i){
		getchar();
		scanf("N = %d",&size);
		Matrix matrix(size);
		bool flag=true;
		for(k=0;k<size;++k){
			for(j=0;j<size;++j){
				scanf("%lld",&matrix.matrix[k][j]);
				if(matrix.matrix[k][j]<0)
					flag= false;
			}
		}
		cout <<"Test #"<<i <<": ";
		if(flag && matrix.isSymmetric())
			cout <<"Symmetric." <<endl;
		else
			cout << "Non-symmetric." <<endl;
	}
}