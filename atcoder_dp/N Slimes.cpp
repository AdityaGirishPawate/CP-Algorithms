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
    vector<int> a(n);
    vector<ll> pre(n+1);
    pre[0]=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        pre[i+1] = pre[i]+a[i];
    }
    ll dp[n][n]; //dp[i][j] -> the minimum cost to combine from interval i to interval j
    for(int L=n-1;L>=0;L--){
        for(int R=L;R<n;R++){
            if(L==R){
                dp[L][R] = 0;
            }
            else{
                ll mn = INF;
                for(int i=L;i<R;i++){
                    mn = min(mn,dp[L][i] + dp[i+1][R] + pre[R+1]-pre[L]);
                }
                dp[L][R] = mn;
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
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
