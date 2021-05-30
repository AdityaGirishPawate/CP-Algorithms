#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5

struct seg_tree{
    int size=1;
    vector<pair<int,int>> minimum;
    void init(int n){
        while(size<n) size*=2;
        minimum.assign(2*size,{0,0LL});
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            minimum[x]={v,1LL};
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        if(minimum[2*x+1].first==minimum[2*x+2].first){
            minimum[x] = {minimum[2*x+1].first,minimum[2*x+1].second+minimum[2*x+2].second};
        }
        else{
            minimum[x] = min(minimum[2*x+1],minimum[2*x+2]);
        }

    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    pair<int,int> Min(int l, int r, int x, int lx, int rx){
        if(l<=lx && r>=rx){
            return minimum[x];
        }
        if(l>=rx || lx>=r){
            return {INF,INF};
        }
        int m=(lx + rx)/2;
        auto b=Min(l,r,2*x+2,m,rx);
        auto a=Min(l,r,2*x+1,lx,m);
        
        if(a.first==b.first){
            return {a.first,a.second+b.second};
        }
        else{
            return min(a,b);
        }
    }
    pair<int,int> Min(int l, int r){
        return Min(l,r,0,0,size);
    }
};


int32_t main() {
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    seg_tree st;
    st.init(n);
    int x;
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        mp[x]++;
        st.set(i,x);
    }
    while(m--){
        int a;
        cin>>a;
        if(a==1){
            int i,v;
            cin>>i>>v;
            st.set(i,v);
        }
        else if(a==2){
            int l,r;
            cin>>l>>r;
            cout<<st.Min(l,r).first<<" "<<st.Min(l,r).second<<endl;
        }
    }
    return 0;
}

