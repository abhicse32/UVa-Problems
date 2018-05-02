#include <cstdio>
#include <cstring>
#include <iostream>
#define repf(a,b,c) for(a=b;a<c;++a)
using namespace std;
void print_arr(int arr[]){
    for(int i=0;i<6;++i)
        printf("%d ",arr[i]);
    printf("\n");
}    

void swap_(int arr[], int i, int j, int k, int l){
    int temp= arr[i];
    arr[i]= arr[k];
    arr[k]= arr[l];
    arr[l]= arr[j];
    arr[j]= temp;
}

void rotation(int arr[]){
    int i,j;
    repf(i,0,2){
        repf(j,0,4){
            print_arr(arr);
            swap_(arr,1,2,3,4);
        }
        swap(arr[0],arr[5]);
        swap(arr[1],arr[4]);
    } 
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int i,j,k,l;
    rotation(arr);
    swap_(arr,0,4,1,5);
    rotation(arr);
    swap_(arr,0,1,4,5);
    print_arr(arr);
    swap_(arr,0,3,2,5);
    rotation(arr);
    swap_(arr,0,2,3,5);
    print_arr(arr);
}
