#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5


int32_t main() {
    ios::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    int max_ele=-1;
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    for (int i = 1; i < a.size()+1; ++i) {
        for (int j = 1; j < b.size()+1; ++j) {
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = 0;
            }
            max_ele = max(max_ele,dp[i][j]);
        }
    }
    cout<<max_ele<<endl;
    return 0;
}

