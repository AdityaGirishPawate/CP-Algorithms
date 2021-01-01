#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5

int32_t main() {
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int x;
    while(k--){
        cin>>x;
        int l=0,r=n;
        bool ans=false;
        while(l<=r){
            int m=(l+r)/2;
            if(a[m]==x){
                ans=true;
                break;
            }
            else if(a[m]>x){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

