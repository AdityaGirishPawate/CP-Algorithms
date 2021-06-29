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

void max_self(ll &a, ll b){
    a = max(a,b);
}

void solve(){
    int n;
    cin>>n;
    vector<int> h(n),b(n);

    //segment tree
    int base =1;
    while(base<=n){
        base*=2;
    }
    vector<ll> tree(2*base);



    for (int i = 0; i < n; ++i) {
        cin>>h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    vector<ll> dp(n+1); // dp[i] -> the max total beauty taken so far with last height as i
    for(int flower=0;flower<n;flower++){
        // max dp[i]
        // for i in [0, h[flower]-1]
        int x = h[flower] + base;
        ll best = 0;
        while(x>1){
            if(x%2 == 1){
                max_self(best,tree[x-1]);
            }
            x >>=1;
        }
        dp[h[flower]] = best + b[flower];
        for(int i=base+h[flower]; i>=1; i/=2){
            max_self(tree[i],dp[h[flower]]);
        }

        /*for(int i=0;i<h[flower];i++){
            max_self(dp[h[flower]],dp[i]+b[flower]);
        }*/
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
        max_self(ans,dp[i]);
    }
    cout<<ans<<"\n";
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
