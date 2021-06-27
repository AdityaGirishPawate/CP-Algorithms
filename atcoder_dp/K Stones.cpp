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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    vector<bool> dp(k+1,false); // dp[i] = true if the player 1 wins with i coins
    for(int i=0;i<=k;i++){
        for(int x:a){
            if(i-x>=0 && !dp[i-x]){
                dp[i] = 1;
            }
        }
    }
    dp[k]? cout<<"First"<<"\n":cout<<"Second\n";
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
