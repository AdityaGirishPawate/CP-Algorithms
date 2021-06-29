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

ll mul(ll a, ll b){
    return (ll)a*b%MOD;
}

void max_self(ll &a, ll b){
    a = max(a,b);
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    //  dp[i][j] -> The number of ways to make the permutation of length i with last character j
    dp[1][1] = 1;
    for(int len=2;len<=n;len++){
        vector<ll> pre(n+1);
        for(int i=1;i<=len-1;i++){
            pre[i] = (pre[i-1] + dp[len-1][i])%MOD;
        }
        for(int b=1;b<=len;b++){
            int L,R;
            if(s[len-2]=='<'){
                L=1,R=b-1;
            }
            else{
                L=b,R=len-1;
            }
            if(L<=R){
                add_self(dp[len][b], (pre[R]-pre[L-1]+MOD)%MOD);
            }
            /*for(int i=L;i<=R;i++){
                add_self(dp[len][b],dp[len-1][i]);
            }*/
        }
    }
    ll answer=0;
    for(int i=1;i<=n;i++){
        add_self(answer,dp[n][i]);
    }
    cout<<answer<<"\n";
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
