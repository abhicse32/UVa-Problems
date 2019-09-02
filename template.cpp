#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define turnoff_jth(N,j) (N& ~(1<<j))
#define toggle_jth(N,j) (N^(1<<j))
#define least_on(N) (N&(-S))
#define turn_off_last_set_bit(S) S^(S&(-S))
#define turn_on_last_zero(S) S|(S+1)

inline int S_mod_N(int S, int N){
	// N is a power of 2
	int i=0;
	while(N){
		N>>=1;
		++i;
	}
	return S&((1<<(i-1))-1);
}

inline bool power_2(int S){
	return !(S&(S-1));
}

int main(){
	int S=89, N=16;
	printf("%d\n",turn_on_last_zero(9));
}