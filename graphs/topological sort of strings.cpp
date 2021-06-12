#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
ll mod=(ll)1e9+7;
vector<vector<int>> adj;
vector<bool> vis,rec;
vector<char> ans;

bool dfs(int i,int p=-1) {
    assert(!vis[i]);
    vis[i] = true;
    bool ok=0;
    rec[i]=1;
    if (!adj[i].empty()) {
        for (int to:adj[i]) {
            if (!vis[to]) {
                if(dfs(to, i)){
                    ok=1;
                }
            }
            else if( rec[to]){
                ok=1;
            }
        }
    }
    rec[i]=0;
    ans.push_back('a'+i);
    return ok;
}

void solve(){
    int n;
    cin>>n;
    string s[n];
    adj.resize(26,vector<int>(0));
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<n;i++){
        string a=s[i-1],b=s[i];
        int l=0,r=0;
        while(l<a.size() && r<b.size() && a[l]==b[r]) {
            l++,r++;
        }
        if(l<a.size() && r==b.size()){
            cout<<"Impossible\n";
            return;
        }
        if(l!=a.size() && r!=b.size()){
            // cout<<a[l]<<" "<<b[r]<<"\n";
            adj[a[l]-'a'].push_back(b[r]-'a');
        }
    }
    ans.clear();
    vis.assign(26,false);
    rec.assign(n,false);
    for(int i=25;i>=0;i--){
        if(!vis[i]){
            //cout<<i<<" ";
            if(dfs(i)){
                cout<<"Impossible\n";
                return;
            }
        }
    }
    cout<<"\n";
    reverse(ans.begin(),ans.end());
    for(char ch:ans){
        cout<<ch;
    }
    cout<<"\n";
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
