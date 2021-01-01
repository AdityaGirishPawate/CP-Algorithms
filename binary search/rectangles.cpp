#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5
int n,w,h;
bool f(int x){
    if((x/w)*(x/h)>=n){
        return true;
    }
    else{
        return false;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin>>w>>h>>n;
    int l=0;
    int r=1;
    while(!f(r)){
        r*=2;
    }
    while(r>l+1){
        int m=(l+r)/2;
        if(f(m)){
            r=m;
        }
        else{
            l=m;
        }
    }
    cout<<r<<endl;
    return 0;
}

