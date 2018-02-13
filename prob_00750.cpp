#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#define vi vector<int>
#define vii vector<vi>

using namespace std;
vii possible_placings;
int size=14;
void get_placings(int row, int col, vi& row_vect){
    if(col>size){
        vi vect= row_vect;
        possible_placings.push_back(vect);
        return;
    }
    int i,j;
    for(i=row;i<=size;++i){
        for(j=1;j<col;++j)
            if(abs(j-col)==abs(row_vect[j]-i) || i==row_vect[j])
                break;
        if(j==col){
            row_vect[col]= i;
            get_placings(1,col+1,row_vect);
            row_vect[col]=-1;
        }
    }
}

int main(){
    int t,i,j,k,m,n;
    vi vect(size+1,-1);
    get_placings(1,1,vect);
    printf("comment\n");
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n");
        for(i=0,j=1;i<possible_placings.size();++i)
            if(possible_placings[i][n]==m){
                printf("\n%2d     ",j++);
                for(k=1;k<=size;++k)
                    printf(" %d",possible_placings[i][k]);
            }
       printf("\n");
       if(t)
          printf("\n"); 
    }
}
