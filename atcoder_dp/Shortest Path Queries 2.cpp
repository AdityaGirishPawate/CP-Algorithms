#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353

#define ll long long

#define INF (ll)1e18+5

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
ll hcf(ll a, ll b)
{
    if (b == 0)
        return a;
    return hcf(b, a % b);
}


ll findlcm(ll a,ll b)
{
    if (b == 1)

        // lcm(a,b)=(a*b)/hcf(a,b)
        return a;

    // assign a=lcm of n,n-1
    a = (a * b) / hcf(a, b);

    // b=b-1
    b -= 1;
    return findlcm(a, b);
}

int gcd(vector<int> c){
    int ans = c[0];
    for(int i=1;i<c.size();i++){
        ans = __gcd(ans,c[i]);
    }
    return ans;
}

int get_zor(int i){
    int zor;
    if(i%4 == 0){
        zor = i;
        //zor = 1;
    }
    if(i%4 == 1){
        zor = 1;
        //zor = i+1;
    }
    if(i%4 == 2){
        zor = i+1;
        //zor = 0;
    }
    if(i%4 == 3){
        zor = 0;
        //zor = i;
    }
    return zor;
}

void solve(){
    int n,m;
    cin>>n>>m;
    ll dp[n][n][n+1];
    for(int k=0;k<=n;k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][k] = INT_MAX;
            }
        }
    }
    for (int i = 0; i <n; ++i) {
        dp[i][i][0]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        dp[a][b][0] = min((ll)c,dp[a][b][0]);
    }
    ll ans=0;
    for(int k=1;k<=n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][k] = min({dp[i][j][k], dp[i][j][k-1], dp[i][k-1][k-1]+dp[k-1][j][k-1]});
                if(dp[i][j][k]<INT_MAX){
                    ans += dp[i][j][k];
                }
            }
        }
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
