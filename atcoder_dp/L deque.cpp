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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        sum+=a[i];
    }
    ll dp[n+1][n+1]; //dp[i][j] -> maximum sum p1 gets between indices i and j
    // transition dp[i][j] = max(dp[i+1][j] + a[i],dp[i][j+1] + a[j])
    // if(i==j)
    for (int i = n-1; i >=0; i--) {
        for (int j = i; j <n; ++j) {
            if(i==j){
                dp[i][j] = a[i];
            }
            else if(i>j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
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
