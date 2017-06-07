#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <bitset>
#define repf(i,start,end) for(i=start;i<end;++i)
#define repb(i,start,end) for(i=end;i>=start;i--)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b) 
#define gc getchar_unlocked
#define size 105
using namespace std;

int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a>b?b:a;}
void swap(int& a,int &b){int temp= a; a=b; b=temp;}

int main(){
	int n,i,j;
	bool matrix[size][size];
	int row_count[size],col_count[size];
	while(si(n),n){
		repf(i,0,n)
			repf(j,0,n) 
				cin >> matrix[i][j]; 
		memset(row_count,0,sizeof row_count);
		memset(col_count,0,sizeof col_count);

		repf(i,0,n)
			repf(j,0,n)
				if(matrix[i][j]){
					row_count[i]++;
					col_count[j]++;
				}
		int odd_row=0, odd_col=0;
		int ind_row, ind_col;
		repf(i,0,n){
			if(col_count[i]&1){
				ind_col= i;
				odd_col++;
			}if(row_count[i]&1){
				ind_row=i;
				odd_row++;
			}
		}
		if(!odd_row && !odd_col)
			cout <<"OK";
		else if(odd_col==1 && odd_row==1)
			cout <<"Change bit ("<<(ind_row+1)<<","<<(ind_col+1)<<")";
		else cout << "Corrupt";
		cout << endl;
	}
}