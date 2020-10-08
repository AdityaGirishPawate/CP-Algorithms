#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<graphics.h>
using namespace std;

void merge(int arr[], int p, int mid,int q){
    int c[q-p+1];
    int i=p,j=mid+1,k=0;
    while(i<=mid && j<=q){
        if(arr[i]>arr[j])
            c[k++]=arr[j++];
        else
            c[k++]=arr[i++];
    }
    while(i<=mid){
        c[k++]=arr[i++];
    }
    while(j<=q){
        c[k++]=arr[j++];
    }
    for (int l = 0; l < q-p+1; ++l) {
        arr[p+l]=c[l];
    }
}

void merge_sort(int arr[],int p,int q){
    if(p>=q){
        return;
    }
    int mid=(p+q)/2;
    merge_sort(arr,p,mid);
    merge_sort(arr,mid+1,q);
    merge(arr,p,mid,q);
}


int main()
{
    int arr[10];
    for(auto &k:arr){
        cin>>k;
    }
    merge_sort(arr,0,9);
    for(auto k:arr){
        cout<<k<<" ";
    }
    cout<<endl;
    return 0;
}
