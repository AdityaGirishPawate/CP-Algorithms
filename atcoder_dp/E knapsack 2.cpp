#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define ll long long
#define INF 1e18L+5
#define MAX_INT (int)10e5+5



void solve(){
    int n,W;
    cin>>n>>W;
    vector<int> w(n),v(n);
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>w[i]>>v[i];
        sum+=v[i];
    }
    vector<ll> dp(sum+1,INF);
    ll ans=INT_MIN;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(ll j=sum-v[i];j>=0;j--){
            dp[j+v[i]] = min(dp[j+v[i]],dp[j]+w[i]);
        }
    }
    for(ll j=0;j<=sum;j++){
        //cout<<dp[j]<<" ";
        if(dp[j]<=W){
            ans=max(ans,(ll)j);
        }
    }
    cout<<ans<<"\n";
}


int main() {
    ios::sync_with_stdio(false);
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
