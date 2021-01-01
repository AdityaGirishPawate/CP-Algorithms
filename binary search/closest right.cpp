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
        int l=-1,r=n+1;
        while(r>l+1){
            int m=(l+r)/2;
            if(a[m]>=x){
                r=m;
            }
            else{
                l=m;
            }
        }
        cout<<r+1<<endl;
    }
    return 0;
}
