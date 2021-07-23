#include<bits/stdc++.h>

using namespace std;


#define mod 1000000007
#define mod1 998244353

#define ll long long
#define pll pair<ll,ll>
#define INF (ll)LLONG_MAX

typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#define pii pair<int,int>

void add_self(ll &a, ll b){
    a += b;
    if(a>=mod){
        a-=mod;
    }
}
void sub_self(ll &a, ll b){
    a -= b;
    if(a<0){
        a+=mod;
    }
}

ll mul(ll a, ll b){
    return (ll)a*b%mod;
}

void max_self(ll &a, ll b){
    a = max(a,b);
}
void min_self(ll &a, ll b){
    a = min(a,b);
}

vector<int> tin,low;
vector<bool> rec,vis;
int timer;
vector<vector<int>> adj;
stack<int> st;
vector<vector<int>> comp;

void dfs(int v, int p=-1){
    vis[v]=true;
    rec[v]=true;
    tin[v]=low[v]=timer++;
    st.push(v);
    for(int to:adj[v]){
        if(to==p) continue;
        else if(vis[to] and rec[to]){
            low[v] = min(low[v],tin[to]);
        }
        else if(!vis[to]){
            dfs(to,v);
            low[v] = min(low[v],low[to]);
        }
    }
    rec[v]=false;
    if(low[v]==tin[v]){
        vector<int> ans;
        while(!st.empty() and st.top()!=v){
            ans.push_back(st.top());
            st.pop();
        }
        if(!st.empty()) ans.push_back(st.top());
        st.pop();
        comp.push_back(ans);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    adj.assign(n,vector<int>());
    timer=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    tin.assign(n,-1);
    low.assign(n,-1);
    vis.assign(n,false);
    rec.assign(n,false);
    comp.clear();
    while(!st.empty()){
        st.pop();
    }
    for(int i=0;i<n;i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (const auto& ele:comp) {
        for (auto out:ele) {
            cout<<out<<" ";
        }
        cout<<"\n";
    }
}



int main(){
    ios_base::sync_with_stdio(false);
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
