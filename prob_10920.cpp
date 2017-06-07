#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define repf(i,a,b) for(i=a;i<b;++i)
#define repb(i,a,b) for(i=b;i>a;--i)

int main(){
	long long sz,p;
	while(scanf("%lld%lld",&sz,&p) && sz!=0){
		int row,col;
		if(p==1)
			col=row= (sz>>1)+1;
		else{
			long long square= ceil(sqrt(p));
			if(!(square&1))
				++square;
			long long largest= square*square;
			row=col=square+((sz- square)>>1);
			if(p>(largest- square)){
				row-=(largest-p);
			}else if(largest-=square,p>(largest-(square-1))){
				row-=(square-1);
				col-=(largest-p+1);
			}else if(largest-=(square-1),p>(largest-(square-1))){
				col-=(square-1);
				row= row-(square-1)+ largest-p+1;
			}else{
				largest-=(square-1);
				row=square+((sz- square)>>1);
				col=col+(p-largest+1);
			}
		}
		cout <<"Line = "<< row<<", column = " << col <<"." <<endl;
	}
}

