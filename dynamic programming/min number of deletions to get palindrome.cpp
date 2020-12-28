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
    cin>>a;
    b=a;
    reverse(a.begin(),a.end());
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    for (int i = 1; i < a.size()+1; ++i) {
        for (int l = 1; l < b.size()+1; ++l) {
            if(a[i-1]==b[l-1]){
                dp[i][l] = dp[i-1][l-1]+1;
            }
            else{
                dp[i][l] = max(dp[i-1][l],dp[i][l-1]);
            }
        }
    }
    int lcs=dp[a.size()][b.size()];
    cout<<"Number of Deletions for getting palindromic subsequence is " <<a.size() - lcs<<"\n";
    return 0;
}

