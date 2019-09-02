#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	char str[20];
	int N,R,base,size,dims,low,up;
	map<char*, vector<int> > myMap;
	int len;
	scanf("%d%d",&N,&R);
	while(N){
		scanf("%s%d%d%d",str,&base,&size,&dims);
		vector<int> vect;
		vect.push_back(base); vect.push_back(size); vect.push_back(dims);
		for(int i=0;i<dims;i++){
			scanf("%d%d",&low,&up);
			vect.push_back(low);
			vect.push_back(up);
		}
		myMap[strdup(str)]= vect;
		N--;
	}
	while(R--){
		scanf("%s%d%d",str,low,up);
		
	}
	// for(map<char*, vector<int> >::iterator iter= myMap.begin(), end= myMap.end(); iter!= end; ++iter){
	// 	cout << iter->first <<" ";
	// 	vector<int> vect= iter->second;
	// 	for(vector<int>::iterator iter2= vect.begin(), end2= vect.end(); iter2!= end2; ++iter2)
	// 		cout << *iter2 <<" ";
	// 	cout <<endl;
	// }
	return 0;
}