#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5


int32_t main() {
    ios::sync_with_stdio(false);
    int n,w;
    cin>>n>>w;
    int arr[n],wt[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i]>>wt[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i]=INT_MIN;
    }
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            if(wt[i-1]<=j && dp[i][j-wt[i-1]]!=INT_MIN){
                dp[i][j] = max(arr[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < w+1; ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(dp[n][w]==INT_MIN){
        cout<<"Not possible to cut rod";
    }
    else{
        cout<<dp[n][w]<<endl;
    }
    return 0;
}
