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

void solve(){
    int n;
    cin>>n;
    vector<vector<bool>> a(n,vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin>>x;
            a[i][j]=x;
        }
    }
    vector<ll> dp(1<<n); // dp[j] -> number of ways of forming pairs for jth man
    dp[0]=1;
    for(int mask=0;mask<(1<<n)-1;mask++){
        ll x = __builtin_popcount(mask);
        for(int y=0;y<n;y++){
            if(a[x][y] and !(mask&(1<<y))){
                ll temp = mask^(1<<y);
                add_self(dp[temp],dp[mask]);
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
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
