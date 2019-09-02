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

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&j,&k);
		int num=0;
		int pow_2= (1<<j);
		while(pow_2){
			if(k>=(pow_2>>=1)){
				num|=pow_2;
				k= (pow_2<<1) - (k+1);
			}
		}
		cout<< num <<endl;
	}
}