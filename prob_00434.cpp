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
#define size 10
using namespace std;

int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a>b?b:a;}
void swap(int& a,int &b){int temp= a; a=b; b=temp;}

int getMin(int* front, int *side, int n){
	bool marked_f[size]={false};
	bool marked_s[size]={false};
	int i,j,k;
	int result=0;
	repf(i,0,n){
		repf(j,0,n){
			if(!marked_f[i] && !marked_s[j] && front[i]==side[j]){
				result+= front[i];
				marked_f[i]=marked_s[j]=true;
			}
		}
	}

	repf(i,0,n){
		if(!marked_f[i]) result+=front[i];
		if(!marked_s[i]) result+=side[i];
	}
	return result;
}
int main(){
	int t,n,i,j,k;
	int front[size],side[size];
	si(t);
	while(t--){
		si(n);
		repf(i,0,n) si(front[i]);
		repf(i,0,n) si(side[i]);
		int front_sum=0, side_sum=0;
		repf(i,0,n){
			front_sum+=front[i];
			side_sum+=side[i];
		}
		front_sum=getMin(front,side,n);
		side_sum=0;
		repf(i,0,n){
			repf(j,0,n)
				side_sum+=min(front[i],side[j]);
		}
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n",
			front_sum,side_sum-front_sum);
	}
}