#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5
int arr[MAX_INT],seg_tree[MAX_INT];

int n;
int e;

vector<vector<int>> adj;
vector<int> visited;
vector<int> d,p;

void bfs(int s){
    queue<int> open;
    visited.assign(n,0);
    p.reserve(n);
    d.assign(n,0);
    open.push(s);
    visited[s] =1;
    p[s]=-1;
    d[s]=0;
    while(!open.empty()){
        int curr = open.front();
        open.pop();
        for(auto k:adj[curr]){
            if(!visited[k]){
                visited[k]=1;
                open.push(k);
                d[k]=d[curr]+1;
                p[k] = curr;
            }
        }
    }
}

void get_shortest_path(int s,int t){
    s--,t--;
    bfs(s);
    cout<<"Distance of "<<s+1<<" from "<<t+1<<" is "<< d[t]<<endl;
    vector<int > path;
    cout<<"The path is"<<endl;
    for (int i = t; i !=-1; i=p[i]) {
        path.push_back(i+1);
    }
    reverse(path.begin(),path.end());
    cout<<s+1;
    for(auto k:path){
        if(s+1!=k) cout<<" -> "<<k;
    }
    cout<<endl;
}

int32_t main() {
    cin>>n;
    cin>>e;
    int a,b;
    adj.reserve(n);
    for (int i = 0; i < e; ++i) {
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin>>q;
    int s,t;
    while(q--){
        cin>>s>>t;
        get_shortest_path(s,t);
    }

    return 0;
}

