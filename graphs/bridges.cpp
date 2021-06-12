#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
ll mod=(ll)1e9+7;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> tin,low;
vector<pii> bridge;
vector<int> parent;

int timer;

int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}

bool erase(vector<int> &x, int y){
    for(int i=0;i<x.size();i++){
        if(x[i]==y){
            x.erase(x.begin()+i);
            return true;
        }
    }
    return false;
}

void dfs(int i,int p=-1){
    assert(!vis[i]);
    vis[i]=true;
    tin[i]=low[i]=timer++;
    for(int to:adj[i]){
        if(to==p) continue;
        if(vis[to]){
            low[i] = min(low[i],tin[to]);
        }
        else{
            dfs(to,i);
            low[i] = min(low[i],low[to]);
            if(low[to]>tin[i]){
                bridge.emplace_back(i,to);
            }
        }
    }
}
void dfs2(int i,int p=-1){
    assert(!vis[i]);
    vis[i]=true;
    parent[i]=p;
    for(int to:adj[i]){
        if(!vis[to]){
            dfs2(to,p);
        }
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
    for(pii ele:bridge){
        //cout<<ele.first<<" "<<ele.second<<"\n";
        erase(adj[ele.first],ele.second);
        erase(adj[ele.second],ele.first);
    }
    vis.clear();
    vis.resize(n,false);
    parent.resize(n);
    int cnt=0;
    iota(parent.begin(),parent.end(),0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs2(i,i);
        }
    }
    cout<<cnt<<"\n";
    for(int ele:parent){
        cout<<ele<<" ";
    }
    bool ok=1;
    while(q--){
        int si,di;
        cin>>si>>di;
        si--,di--;
        if(find(si)!=find(di)){
            ok=0;
        }
    }
    if(ok){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    };
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
