#include <iostream>
#include <bitset>
#include <stdlib.h>
#include <cstdio>
using namespace std;
#define gc getchar_unlocked
inline int fast(){
	int n=0;
	char ch=gc();
	while(ch<48)ch=gc();
	while(ch>47){
		n=(n<<1)+(n<<3)+(ch-48);
		ch=gc();
	}
	return n;
}

int main(){
	int N,n,k;
	bitset<32> num;
	N=fast();
	while(N--){
		n=fast(); k=fast();
		int temp;
		while(n){
			temp= k-(1<<(n-1));
			if(temp >= 0 && !((temp>>n)&1))
				num[n-1]=1;
			n--;
		}
		cout << num.to_ulong() <<endl;
		num.reset();
	}
	return 0;
}