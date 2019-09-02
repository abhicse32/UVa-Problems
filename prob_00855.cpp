#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,b,n) for(i=n;i>=b;i--)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;
#define size 50005
int main(){
	int i,j,k,t;
	int a,s,f;
	int arr_s[size], arr_a[size];
	si(t);
	while(t--){
		sii(s,a); si(f);
		repf(i,0,f)
			sii(arr_s[i],arr_a[i]);
		sort(arr_a,arr_a+f);
		sort(arr_s,arr_s+f);
		int mid=((f-1)>>1);
		printf("(Street: %d, Avenue: %d)\n",arr_s[mid],arr_a[mid]);
	}
}