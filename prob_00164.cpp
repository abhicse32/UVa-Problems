#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

// assuming cost of deletion, insertion, and replacement costs are 1

string edit(string str1, string str2){
	int len1= str1.length();
	int len2= str2.length();
	int cost_matrix[len1+1][len2+1];

	int deletion_cost=1,insertion_cost=1,replacement_cost=1;

	for(int i=0;i<=len2;++i)
		cost_matrix[0][i]=i;
	for(int i=0;i<=len1;++i)
		cost_matrix[i][0]=i;
	for(int i=1;i<=len1;++i){
		for(int j=1;j<=len2;++j){
			if(str1[i-1]==str2[j-1])
				cost_matrix[i][j]=cost_matrix[i-1][j-1];
			else
				cost_matrix[i][j]=min(cost_matrix[i-1][j-1]+replacement_cost,
							min(cost_matrix[i-1][j]+deletion_cost,cost_matrix[i][j-1]+insertion_cost));
		}
	}
	string sol="";
	for(int i=len1;i>=0;){
		for(int j=len2;j>=0;){
		
		}
	}
}

int main(){
	string str1,str2;
	while(cin>>str1 && str1!="#"){
		cin >> str2;
		string sol=edit(str1,str2);
		cout << sol <<endl;
	}
}