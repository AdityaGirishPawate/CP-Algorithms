#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5


void solve(){

}

int32_t main() {
    int n;
    cin>>n;
    int w;
    cin>>w;
    vector<int> wt(n);
    vector<int> val(n);
    vector<vector<bool>> dp(n+1,vector<bool>(w+1,false));
    for (int i = 0; i < n; ++i) {
        cin>>wt[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < w; ++j) {
            if(i==0){
                dp[i][j] = false;
            }
            if(j==0){
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            if(wt[i-1]<=j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-wt[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][w] <<endl;
    return 0;
}

