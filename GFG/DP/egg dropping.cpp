// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        swap(n,k);
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
        // if number of floors is 0,1 and eggs>0 ans=0
        // if number of eggs=0 and floors>0 ans=INF
        for(int i=0;i<=k;i++){
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=INT_MAX;
            dp[i][1]=i;
        }
        
        for(int f=2;f<=n;f++){
            for(int e=2;e<=k;e++){
                for(int x=1;x<=f;x++){
                    int res = max(dp[f-x][e],dp[x-1][e-1])+1;
                    if(res<dp[f][e]){
                        dp[f][e]=res;
                    }
                }
            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
