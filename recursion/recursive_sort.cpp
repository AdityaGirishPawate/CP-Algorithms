#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<graphics.h>
using namespace std;

void Insert(int arr[],int n,int element){
    if(n<0){
        arr[0]=element;
    }
    if(element>=arr[n]){
        arr[n+1]=element;
    }
    else{
        arr[n+1]=arr[n];
        Insert(arr,n-1,element);
    }
}

void Sort(int arr[],int n){
    if(n==0){
        return;
    }
    Sort(arr,n-1);
    Insert(arr,n-1,arr[n]);

}

int main()
{
    int arr[10];
    for (int & i : arr) {
        cin>>i;
    }
    Sort(arr,9);
    for (int  i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
