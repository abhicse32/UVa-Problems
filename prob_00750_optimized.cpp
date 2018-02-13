#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <bitset>
#define vi vector<int>
#define vii vector<vi>

using namespace std;
vii possible_placings;
bitset<30> ld,rd,rw;

int size=8;
void get_placings(int row, int col, vi& row_vect){
    if(col>size){
        vi vect= row_vect;
        //for(auto& val:vect)
        //    cout << val <<" ";
        //cout <<endl;
        possible_placings.push_back(vect);
        return;
    }
    int i,j,end_=(col==1?((size+1)>>1):size);
    for(i=row;i<=end_;++i){
        if(!rw[i] && !ld[i+col-1] && !rd[i-col+size]){
            row_vect[col]= i;
            rw[i]= ld[i+col-1]= rd[i-col+size]= 1;
            get_placings(1,col+1,row_vect);
            row_vect[col]=-1;
            rw[i]=ld[i+col-1]=rd[i-col+size]=0; 
        }
    }
}

int main(){
    int t,i,j,k,m,n;
    vi vect(size+1);
    get_placings(1,1,vect);
    i=possible_placings.size()-1;
    k= (size+1)>>1;
    t= size&1?0:1;

    if(size&1)
        while(possible_placings[i][1]==k)--i;
    for(;i>=0;--i){
        vi vect(size+1);
        vect[1]= (k<<1)-possible_placings[i][1]+t;
        for(j=2;j<=size;++j)
            vect[j]=(vect[1]+possible_placings[i][1]-possible_placings[i][j]);    
        possible_placings.push_back(vect);
    }
    /*for(auto&val: possible_placings){
        for(auto&val1: val)
            cout << val1 <<" ";
        cout <<endl;
    }*/
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
