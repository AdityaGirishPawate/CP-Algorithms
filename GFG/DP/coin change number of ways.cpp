#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PII pair<int,int>
void solve(){
    int n,sum;
    cin>>n>>sum;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(v[i-1]<=j){
                dp[i][j] += dp[i][j-v[i-1]];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<dp[n][sum];
}

int main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
