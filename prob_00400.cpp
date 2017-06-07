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

int main(){
	int n,i,j,k;
	vector<string> vect;
	string str;
	int max_len;
	while(scanf("%d\n",&n)!=EOF){
		max_len=0;
		repf(i,0,n){
			getline(cin,str);
			vect.push_back(str);
		}
		sort(vect.begin(),vect.end());
		for(vector<string>::iterator iter= vect.begin(), end= vect.end();
						iter!= end; ++iter){
			int len= iter->length();
			if(max_len< len)
				max_len= len;
		}
		int m=62/(max_len+2);
		k=ceil(n/float(m));
		repf(i,0,60) putchar('-');
		putchar('\n');	
		repf(i,0,k){
			for(j=i;j<n;j+=k){
				if(j+k < n)
					cout << setw(max_len+2);
				cout <<left << vect[j] ;
			}
			puts("");
		}
		vect.clear();
	}
}