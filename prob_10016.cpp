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
#define repb(i,a,b) for(i=a;i>b;--i)

class Matrix{
public:
	int** matrix;
	int size;
	Matrix(int sz):size(sz){
		matrix= new int*[size];
		int i;
		repf(i,0,size)
			matrix[i] = new int[size];
	}
	Matrix():size(0){};

	friend ostream& operator<<(ostream& os, Matrix &mat){
		for(int i=0;i<mat.size;++i){
			os<<mat.matrix[i][0];
			for(int j=1;j<mat.size;++j)
				os<<" "<< mat.matrix[i][j];
			os<<endl;
		}
		return os;
	}
	// operation 1 - upside-down flip

	Matrix& upside_down_flip(int ring_num){
		int start= ring_num- 1;
		int end= size- ring_num;

		for(int i=start;i<=end;++i)
			swap(matrix[start][i],matrix[end][i]);
		for(int i= start+1,j=end-1;i<j;++i,--j){
			swap(matrix[i][start],matrix[j][start]);
			swap(matrix[i][end], matrix[j][end]);
		}
		return *this;
	}

	// operation 2- left_right_flip
	Matrix& left_right_flip(int ring_num){
		int start= ring_num-1, end= size- ring_num;
		for(int i=start;i<=end;++i)
			swap(matrix[i][start], matrix[i][end]);
		for(int i= start+1,j= end-1;i<j;++i,--j){
			swap(matrix[start][i],matrix[start][j]);
			swap(matrix[end][i], matrix[end][j]);
		}
		return *this;
	}

	// operation 3- flip_through main diagonal
	Matrix& flip_through_main_diagonal(int ring_num){
		int start= ring_num-1, end= size- ring_num;
		for(int i=start+1;i<=end;++i)
			swap(matrix[i][start], matrix[start][i]),
			swap(matrix[end][i],matrix[i][end]);
	}

	// operation 4- flip through inverse diagonal
	Matrix& flip_through_Inverse_diagonal(int ring_num){
		int start= ring_num-1, end= size- ring_num;
		for(int i=end-1,j=start+1;i>=start;--i,++j)
			swap(matrix[i][start], matrix[end][j]),
			swap(matrix[start][j],matrix[i][end]);
	}
};

// 1- upside-down flip
// 2- left-Right flip
// 3- flip through the main diagonal
// 4- flip through the main Inverse diagonal

int main(){
	int n,size;
	int i,j,k;
	Matrix matrix1;
	string str;
	scanf("%d\n",&n);
	while(n--){
		scanf("%d\n",&size);
		matrix1=Matrix(size);
		repf(i,0,size){
			getline(cin,str);
			stringstream stream(str);
			for(j=0;stream >> k;++j)
				matrix1.matrix[i][j]=k;
		}

		int rings= (size>>1)+(size&1);
		for(int i=1;i<=rings;++i){
			getline(cin,str);	
			stringstream stream(str);
			stream >>k;
			while(stream>> k){
				switch(k){
					case 1: matrix1.upside_down_flip(i); break;
					case 2:	matrix1.left_right_flip(i); break;
					case 3: matrix1.flip_through_main_diagonal(i);break;
					case 4: matrix1.flip_through_Inverse_diagonal(i); break;
					default: break;
				}	
			}
		}
		cout << matrix1;
	}
}