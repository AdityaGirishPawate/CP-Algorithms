#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define pll pair<ll,ll>


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            if(x=='#'){
                dp[i][j]=INT_MIN;
            }
        }
    }
    ll mod=(ll)1e9+7;
    dp[0][0]=1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(dp[i][j]!=INT_MIN){
                if((i-1>=0)&&(dp[i-1][j]!=INT_MIN)){
                    dp[i][j]+=dp[i-1][j]%mod;
                }
                if((j-1>=0)&&(dp[i][j-1]!=INT_MIN)){
                    dp[i][j]+=dp[i][j-1]%mod;
                }
            }
        }
    }
    cout<<dp[n-1][m-1]%mod;
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
