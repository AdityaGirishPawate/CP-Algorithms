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
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    for (int i = 1; i < a.size()+1; ++i) {
        for (int j = 1; j < b.size()+1; ++j) {
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=a.size(),j=b.size();
    string ans;
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else {
            ans+=a[i-1];
            i--;
            j--;
        }
    }
    i=0,j=0;
    int k=0;
    reverse(ans.begin(),ans.end());
    string full_ans;
    full_ans.clear();
    int count = a.size() + b.size() -dp[a.size()][b.size()];
    cout<<count<<endl;
    while(count){
        if(a[i]!=ans[k]){
            full_ans += a[i];
            i++;
            count--;
        }
        if(b[j]!=ans[k]){
            full_ans += b[j];
            j++;
            count--;
        }
        if(a[i]==ans[k] && b[j]==ans[k]){
            full_ans += ans[k];
            count--;
            k++;
            i++;
            j++;
        }
    }
    cout<<ans<<endl<<full_ans<<endl;
    return 0;
}

