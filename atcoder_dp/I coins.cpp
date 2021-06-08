#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define ll long long
#define INF 1e18L+5
#define MAX_INT (int)10e5+5


void solve(){
    int N;
    cin>>N;
    vector<double> dp(N+1,0);
    // dp[i] -> probability of i heads so far
    dp[0]=1;
    for(int co=0;co<N;co++){
        double x;
        cin>>x;
        for(int i=co+1;i>=0;i--){
            dp[i] = (i==0?0:dp[i-1]*x) + dp[i]*(1-x);
        }
    }
    double ans=0;
    for(int i=0;i<=N;i++){
        if(i > N-i){
            ans+=dp[i];
        }
    }
    cout<<setprecision(10)<<ans;
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
