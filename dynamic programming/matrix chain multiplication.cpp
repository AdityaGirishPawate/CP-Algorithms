#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5

int32_t main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if(i>=j){
                dp[i][j]=0;
            }
        }
    }
    for (int l = 2; l <= n ; ++l) {
        for (int i = 1; i < n-l+1; ++i) {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
            }
        }
    }
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            cout<<setw(6)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[1][n-1]<<endl;
    return 0;
}

