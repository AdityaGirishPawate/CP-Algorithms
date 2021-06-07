#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define ll long long
#define INF 1e18L+5
#define MAX_INT (int)10e5+5

vector<vector<int>> edge;
vector<bool> vis;
vector<int> indegree;
vector<int> dist;

void dfs(int i){
    assert(!vis[i]);
    vis[i]=true;
    for(auto b:edge[i]){
        indegree[b]--;
        dist[b]=max(dist[b],dist[i]+1);
        if(indegree[b]==0){
            dfs(b);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    edge.resize(n);
    vis.assign(n,false);
    indegree.assign(n,0);
    dist.assign(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a-1].push_back(b-1);
        indegree[b-1]++;
    }
    for(int i=0;i<n;i++){
        if(!vis[i] && indegree[i]==0){
            dfs(i);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //cout<<dist[i]<<"\n";
        ans=max(ans,dist[i]);
    }
    cout<<ans<<"\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
