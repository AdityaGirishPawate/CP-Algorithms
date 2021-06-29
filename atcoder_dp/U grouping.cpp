#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18+10

#define ll long long

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

ll mul(ll a, ll b){
    return (ll)a*b%MOD;
}

void max_self(ll &a, ll b){
    a = max(a,b);
}
vector<ll> dp; // dp[i] - > the maximum possible value in this sequence of taking
//vector<ll> pre;

void rec(int i, const vector<int> &not_taken, ll score, int mask, int group,vector<ll> &pre){
    if(i==(int)not_taken.size()){
        dp[mask] = max(dp[mask],score + pre[group]);
        return;
    }
    rec(i+1,not_taken,score,mask,group,pre);
    rec(i+1, not_taken,score,mask^(1<<not_taken[i]),group^(1<<not_taken[i]),pre);
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>a[i][j];
        }
    }
    dp.assign(n,-INF);
    vector<ll> pre((1<<n));
    // O(2^N * N^2)
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                for(int j=i+1;j<n;j++){
                    if(mask&(1<<j)){
                        pre[mask]+=a[i][j];
                    }
                }
            }
        }
    }
    //O(2^n * n + 3^n)
    dp[0]=0;
    for(int mask=0;mask< ( 1<<n); mask++){
        vector<int> not_taken;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))){
                not_taken.push_back(i);
            }
        }
        rec(0,not_taken,dp[mask],mask,0,pre);
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
