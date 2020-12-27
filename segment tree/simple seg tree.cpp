#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5

struct seg_tree{
    int size=0;
    vector<int> sums;

    void init(int n){
        size=1;
        while(size<n) size*=2;
        sums.assign(2*size,0LL);
    }
    void set(int i,int v, int x, int lx,int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];

    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int sum(int l, int r,int x,int lx,int rx){
        if(lx>=l && rx<=r){
            return sums[x];
        }
        if(rx<=l || lx>=r){
            return 0;
        }
        int a,b;
        int m=(lx+rx)/2;
        a = sum(l,r,2*x+1,lx,m);
        b = sum(l,r,2*x+2,m,rx);
        return a+b;
    }
    int sum(int l,int r){
        return sum(l,r,0,0,size);
    }

};


int32_t main() {
    int n,m;
    cin>>n>>m;
    seg_tree st;
    st.init(n);
    int x;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        st.set(i,x);
    }
    int a;
    while(m--){
        cin>>a;
        if(a==1){
            int i,v;
            cin>>i>>v;
            st.set(i,v);
        }
        else if(a==2){
            int l,r;
            cin>>l>>r;
            cout<<st.sum(l,r)<<endl;
        }
    }

    
    return 0;
}

/*
sample test case
5 5
5 4 2 3 5
2 0 3
1 1 1
2 0 3
1 3 1
2 0 5*/
