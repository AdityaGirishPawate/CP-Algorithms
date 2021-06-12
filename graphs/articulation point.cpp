#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
ll mod=(ll)1e9+7;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> tin,low;
int timer;
vector<int> art;

void dfs(int i,int p=-1){
    assert(!vis[i]);
    vis[i]=true;
    tin[i]=low[i]=timer++;
    int children=0;
    for(int to:adj[i]){
        if(to==p) continue;
        if(vis[to]){
            low[i] = min(low[i],tin[to]);
        }
        else{
            dfs(to,i);
            low[i] = min(low[i],low[to]);
            if(low[to]>=tin[i] && p!=-1){
                cout<<tin[i]<<"\n";
                art.push_back(i);
            }
            children++;
        }
    }
    if(p==-1 && children>1){
        art.push_back(i);
    }
}

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    timer=0;
    vis.assign(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int ele:art){
        cout<<ele+1<<" ";
    }
}

int main(){
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
