#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define pll pair<ll,ll>

pll getmin(pll a, pll b){
    if(a.first<b.first){
        return a;
    }
    else{
        return b;
    }
}

void solve(){
    string a,b;
    cin>>a>>b;
    ll n=a.size(),m=b.size();
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    ll l=n,r=m;
    while(l>0 && r>0){
        if(a[l-1]==b[r-1]){
            l--,r--;
            ans+=a[l];
        }
        else{
            if(dp[l-1][r]>dp[l][r-1]){
                l--;
            }
            else{
                r--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
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
