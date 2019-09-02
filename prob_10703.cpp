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
#define size 505
using namespace std;

void swap(int& a,int &b){int temp= a; a=b; b=temp;}
int main(){
	int W,H,N,i,j;
	int x1,x2,y1,y2;
	bool arr[size][size];
	while(sii(W,H), si(N), W && H && N){
		memset(arr,0,sizeof arr);
		int count=0;
		while(N--){
			sii(x1,y1); sii(x2,y2);
			int min_x= min(x1,x2);
			int max_x= max(x1,x2);
			int min_y= min(y1,y2);
			int max_y= max(y1,y2);
			
		}
	}	
}