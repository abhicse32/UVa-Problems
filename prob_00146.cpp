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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,b,n) for(i=n;i>=b;i--)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;

int main(){
	string str;
	while(getline(cin, str), str!="#"){
		if(next_permutation(str.begin(),str.end()))
			cout << str <<endl;
		else cout <<"No Successor\n";	
	}
}