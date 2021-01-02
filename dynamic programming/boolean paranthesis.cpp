#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5

int32_t main() {
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(s.size(),vector<int>(2)));
    for (int i = 0; i < s.size(); i++) {
        dp[i][i][0] = s[i]=='F';
        dp[i][i][1] = s[i]=='T';
    }
    for (int l = 3; l <= s.size(); l+=2) {
        for (int i = 0; i < s.size()-l+1; i+=2) {
            int j=i+l-1;
            for (int k = i; k < j; k+=2) {
                if(s[k+1]=='&'){
                    dp[i][j][0] += dp[i][k][1]*dp[k+2][j][0]+dp[i][k][0]*dp[k+2][j][1]+dp[i][k][0]*dp[k+2][j][0];
                    dp[i][j][1] += dp[i][k][1]*dp[k+2][j][1];
                }
                else if(s[k+1]=='|'){
                    dp[i][j][1] += dp[i][k][1]*dp[k+2][j][0]+dp[i][k][0]*dp[k+2][j][1]+dp[i][k][1]*dp[k+2][j][1];
                    dp[i][j][0] += dp[i][k][0]*dp[k+2][j][0];
                }
                else if(s[k+1]=='^'){
                    dp[i][j][1] += dp[i][k][0]*dp[k+2][j][1]+dp[i][k][1]*dp[k+2][j][0];
                    dp[i][j][0] += dp[i][k][0]*dp[k+2][j][0]+dp[i][k][1]*dp[k+2][j][1];
                }
            }
        }
    }
    cout<<dp[0][s.size()-1][true]<<endl;
    return 0;
}

