#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    ll sum=0;
    ll dp[k+1]; //dp[j] is the number of ways of getting sum j with all children
    fill(dp,dp+k+1,0);
    dp[0] = 1;
    for(int child=0;child<n;child++){
        int inp;
        cin>>inp;
        vector<ll> fake(k+1,0);
        for(int num = k-1; num>=0; num--) {
            int L = num + 1;
            int R = min(k,num+inp);
            add_self(fake[L],dp[num]);
            if(R+1 <= k){
                sub_self(fake[R+1],dp[num]);
            }
        }
        for(int i=1;i<=k;i++){
            add_self(fake[i],fake[i-1]);
            add_self(dp[i],fake[i]);
        }
    }
    cout<<dp[k]<<"\n";
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
