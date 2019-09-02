#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <sstream>
using namespace std;

class Matrix{
public:
	int size;
	char**matrix;
	Matrix(int sz):size(sz){
		matrix= new char*[size];
		for(int i=0;i<size;++i)
			matrix[i]= new char[size+1];
	} 

	Matrix(){}

	friend ostream& operator<<(ostream& os, Matrix& mat){
		for(int i=0;i<mat.size;++i)
			os<< mat.matrix[i]<<endl;
		return os;
	}

	void inc(){
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j)
				matrix[i][j]= '0'+ (matrix[i][j]+1-'0')%10;
		}
	}

	void dec(){
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j)
				matrix[i][j]= matrix[i][j]-1<'0'?
					matrix[i][j]+9:matrix[i][j]-1;
		}
	}

	void row(int a, int b){
		swap(matrix[--a],matrix[--b]);
	}

	void col(int a, int b){
		--a; --b;
		for(int i=0;i<size;++i)
			swap(matrix[i][a], matrix[i][b]);
	}

	void transpose(){
		for(int i=0;i<size;++i){
			for(int j=i;j<size;++j)
				swap(matrix[i][j],matrix[j][i]);
		}
	}

};

int main(){
	int t,i,j,k,n;
	int a,b;
	int ops;
	string str;
	Matrix matrix(9);
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d\n",&n);
		matrix.size=n;
		for(int k=0;k<n;++k)
			scanf("%s",matrix.matrix[k]);
		scanf("%d\n",&ops);
		for(int k=0;k<ops;++k){
			getline(cin,str);
			stringstream stream(str);
			stream >> str;
			if(str=="inc"){
				matrix.inc();
			}else if(str=="dec"){
				matrix.dec();
			}else if(str=="row"){
				stream >> a >> b;
				matrix.row(a,b);
			}else if(str=="col"){
				stream >> a >> b;
				matrix.col(a,b);
			}else{
				matrix.transpose();
			}
		}
		cout <<"Case #"<<i<<endl;
		cout << matrix <<endl;
	}
}