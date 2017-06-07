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

		bool operator==(Matrix &mat){
			for(int i=0;i<size;++i){
				for(int j=0;j<size;++j)
					if(matrix[i][j]!=mat.matrix[i][j])
						return false;
			}
			return true;
		}

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

		Matrix& vertical_reflection(){
			int half= (size>>1);
			for(int i=0;i<half;++i)
				swap(matrix[i],matrix[size-i-1]);
			return (*this);
		}
};

int main(){
	Matrix matrix1, matrix2, matrix3;
	string str;
	int n;
	int count=1;
	while(scanf("%d\n",&n)==1){
		matrix1= Matrix(n);
		matrix2= Matrix(n);
		for(int i=0;i<n;++i){
			getline(cin,str);
			int j=0;	
			while(str[j]!=' ')
				matrix1.matrix[i][j]= str[j++];
			matrix1.matrix[i][j++]='\0';
			int k=0;
			while(str[j])
				matrix2.matrix[i][k++]= str[j++];
			matrix2.matrix[i][k]='\0';
		}
		printf("Pattern %d was ",count);
		if(matrix1==matrix2)
			printf("preserved.\n");
		else if(matrix1.rotate_90_degrees()== matrix2)
			printf("rotated 90 degrees.\n");
		else if( matrix1.rotate_90_degrees()==matrix2)
			printf("rotated 180 degrees.\n");
		else if(matrix1.rotate_90_degrees()==matrix2)
			printf("rotated 270 degrees.\n");
		else{
			matrix1.rotate_90_degrees();
			if(matrix1.vertical_reflection()==matrix2)
				printf("reflected vertically.\n");
			else if(matrix1.rotate_90_degrees()==matrix2)
				printf("reflected vertically and rotated 90 degrees.\n");
			else if(matrix1.rotate_90_degrees()==matrix2)
				printf("reflected vertically and rotated 180 degrees.\n");
			else if(matrix1.rotate_90_degrees()==matrix2)
				printf("reflected vertically and rotated 270 degrees.\n");
			else printf("improperly transformed.\n");
		}
		++count;
	} 
}