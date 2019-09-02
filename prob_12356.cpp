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
#define size 100005
using namespace std;

int main(){
	int i,j,k,s,b,l,r;
	int left[size],right[size];

	while(sii(s,b), s || b){
		repf(i,1,s+1){
			left[i]=i-1;
			right[i]=i+1;
		}
		left[1]= -1; right[s]=-1;
		while(b--){
			sii(l,r);
			if(left[l]==-1)
				printf("* ");
			else printf("%d ",left[l]);
			if(right[r]==-1)
				printf("*\n");
			else printf("%d\n",right[r]);
			left[right[r]]=left[l];
			right[left[l]]=right[r];
		}
		puts("-");
	}
}