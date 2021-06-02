#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
    dp[1][0] = max(b[0],c[0])+a[1];
    dp[1][1] = max(a[0],c[0])+b[1];
    dp[1][2] = max(a[0],b[0])+c[1];
    for(int i=2;i<n;i++){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+c[i];
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
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
