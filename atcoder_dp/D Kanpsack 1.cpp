#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    ll n,W;
    cin>>n>>W;
    vector<ll> v(n),w(n);
    vector<vector<ll>> dp(n+1,vector<ll>(W+1,0));
    for(ll i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    for(ll i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(ll i=1;i<=W;i++){
        dp[0][i]=INT_MIN;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=W;j++){
            if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    ll ans=0;
    for(int i =0; i<=W;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
}

int main(){
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
};
