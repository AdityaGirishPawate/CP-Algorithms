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
int n;

void solve(){
    ll d;
    string k;
    cin>>k;
    cin>>d;
    vector<vector<ll>> dp(d,vector<ll>(2));
    /*
     * dp[i][j] -> the number of ways to get sum as i and j is whether the digit is smaller or not
     *
     * */
    dp[0][0]=1;
    for(int len=0;len<k.size();len++){
        vector<vector<ll>> new_dp(d,vector<ll>(2));
        for(int sum=0;sum<d;sum++){
            for(bool small:{false,true}){
                for(int digit=0;digit<10;digit++){
                    if(digit > k[len]-'0' and !small) break;
                    add_self(new_dp[(sum+digit)%d][small || (digit < k[len]-'0')], dp[sum][small]);
                }
            }
        }
        dp = new_dp;
    }
    cout<< ( dp[0][false] + dp[0][true] -1 + MOD)%MOD<<"\n";
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
