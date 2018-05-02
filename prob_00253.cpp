#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

void swap_(char str[], int i, int j, int k, int l){
    char temp= str[i];
    str[i]= str[k];
    str[k]= str[l];
    str[l] = str[j];
    str[j]= temp; 
}

bool check_if_equal_on_rotation(char str1[],char str2[]){
    int j,i;
    repf(i,0,2){
        repf(j,0,4){
           if(strcmp(str1,str2)==0) return true;
           swap_(str1,1,2,3,4);
        }
        swap(str1[0],str1[5]);
        swap(str1[1],str1[4]);
    }
    return false;
}

int main(){
    int i,j,k,l,m,n;
    char str1[15],str2[8],str3[8];
    while(scanf("%s",str1)!=EOF){
        strcpy(str2,str1+6);
        //printf("%s\n",str1);
        str1[6]='\0';
        bool flag=true;
        if(!check_if_equal_on_rotation(str1,str2)){
            swap_(str1,0,4,1,5);
            if(!check_if_equal_on_rotation(str1,str2)){
                swap_(str1,0,1,4,5);
                swap_(str1,0,3,2,5);
                if(!check_if_equal_on_rotation(str1,str2))
                    flag= false;
            }
        } 
        if(flag)
            printf("TRUE\n"); 
        else printf("FALSE\n");
    }
}
