#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),dp(n+1,INT_MAX);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k && i-j>=0;j++){
            dp[i] = min(dp[i],dp[i-j]+ abs(a[i]-a[i-j]));
        }
    }
    cout<<dp[n-1];
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
