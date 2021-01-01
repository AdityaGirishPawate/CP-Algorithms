#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5

bool is_palindrome(const string& s,int i,int j){
    string k=s.substr(i,j-i+1);
    string rev=k;
    reverse(k.begin(),k.end());
    return  rev == k;
}

int32_t main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin>>s;
    n=s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int l = 1; l < n+1; ++l) {
        for (int i = 0; i < n-l+1; ++i) {
            int j = i+l-1;
            if(i==j || is_palindrome(s,i,j)){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=INT_MAX;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
                }
            }
        }
    }
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            cout<<setw(6)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}

