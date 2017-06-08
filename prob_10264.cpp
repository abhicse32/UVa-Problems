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
#define SIZE 20000

int main(){
	int i,j,k;
	int n;
	short arr[SIZE];
	int potency[SIZE];

	while(scanf("%d",&n)!=EOF){
		int corners=(1<<n);
		rep(i,0,corners)
			scanf("%d",&j),
			arr[i]= j;
		memset(potency,0,sizeof(potency[0])*SIZE);
		rep(i,0,corners){
			rep(j,0,n){
				int nbr= i^(1<<j);
				potency[i]+=arr[nbr];
			}
		}
		int max_sum=-1;
		rep(i,0,corners){
			rep(j,0,n){
				int nbr= i^(1<<j);
				int sum= potency[i]+potency[nbr];
				if(sum> max_sum)
					max_sum= sum;
			}
		}
		cout << max_sum <<endl;
	}
}