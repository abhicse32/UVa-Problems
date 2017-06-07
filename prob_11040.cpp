#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
	int i,j,k;
	int n;
	scanf("%d\n",&n);
	vector<vector<int> > vect;
	for(int i=1;i<=9;++i)
		vect.push_back(vector<int>(i));

	while(n--){
		for(int i=0;i<9;i+=2)
			for(int j=0;j<=i;j+=2)
				scanf("%d",&k),vect[i][j]=k;
		
		for(int i=1,j=0;i<8;i+=2,j+=2)
			vect[8][i] = ((vect[6][j] - vect[8][j] - vect[8][j+2])>>1);
		
		for(int i=7;i>=0;--i){
			for(j=0;j<=i;++j)
				vect[i][j]= vect[i+1][j]+ vect[i+1][j+1];
		}
		for(int i=0;i<9;++i){
			cout << vect[i][0];
			for(int j=1;j<=i;++j)
				cout <<" " << vect[i][j];
			cout << endl;
		}	
	}
}