#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18+10

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#define pii pair<int,int>

void add_self(ll &a, ll b){
    a += b;
    if(a>=MOD){
        a-=MOD;
    }
}
void sub_self(ll &a, ll b){
    a -= b;
    if(a<0){
        a+=MOD;
    }
}
vector<vector<int>> adj;
vector<bool> vis;

ll mul(int a, int b){
    return (ll)a*b%MOD;
}

// return number of ways of coloring {black,white}
pii dfs(int x, int par=-1){
    int all_white = 1; // number of ways of coloring x black
    int at_1_black = 0; // number of ways of coloring x white - number of ways coloring x black
    for(int to:adj[x]){
        if(to!=par){
            pii temp = dfs(to,x);
            int temp_val = all_white;
            all_white = mul(all_white,temp.second);
            at_1_black = (int)(mul(at_1_black,temp.first+temp.second) + mul(temp_val,temp.first))%MOD;
        }
    }
    return {all_white, (all_white+at_1_black)%MOD};
}

void solve(){
    int n;
    cin>>n;
    adj.assign(n+1,vector<int>());
    vis.assign(n+1,false);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pii ans = dfs(1);
    cout<<(ans.first+ans.second)%MOD;
}


int main(){
    fastio();
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
