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
#include <climits>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
using namespace std;
#define SIZE 10000

int main(){
	int i,j,k,n;
	int y,a,b;
	int arr[SIZE];

	for(j=1;scanf("%d",&n),n;++j){
		memset(arr,0,sizeof(arr[0])*SIZE);
		rep(i,0,n){
			scanf("%d%d%d",&y,&a,&b);
			int diff= b-a;
			for(k=y;k<SIZE;k+=diff)
				++arr[k];
		}

		cout <<"Case #"<<j<<":" <<endl;
		bool flag=false;
		rep(i,0,SIZE){
			if(arr[i]==n){
				flag=true;
				printf("The actual year is %d.\n\n",i);
				break;
			}
		}
		if(!flag)
			cout << "Unknown bugs detected.\n\n";
	}
}