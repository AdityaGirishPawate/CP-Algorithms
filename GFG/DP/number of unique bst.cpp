// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ll long long

class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    ll mod=(long long)1e9+7;
    int numTrees(int N) 
    {
        ll dp[2*N+1];
        fill(dp,dp+2*N+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=N;i++){
            for(int j=1;j<=i;j++){
                dp[i] = (dp[i] + dp[i-j]*dp[j-1])%mod;
            }
        }
        return (dp[N])%mod;
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends
