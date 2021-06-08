// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends




class Solution
{
    public:
    //Function to return nCr mod 10^9+7 for given n and r. 
    int nCrModp(int n, int r) 
    {
        int mod=(int)1e9+7;
        int dp[n+1];
        fill(dp,dp+n+1,0);
        if(r>n)return 0;
        if(r>n-r)
            r = n-r;
        long long ans=1;
        for(int i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
            ans%=mod;
        }
        return ans%mod;
    } 
};

// { Driver Code Starts.
// Driver program 
int main() 
{ 
  int t, n, r;
  
  //taking count of testcases
  cin >> t;
  
  while(t--){
      
      //taking n and r
      cin >> n >> r;
      Solution ob;
      //calling method nCrModp()
      cout << ob.nCrModp(n, r) << endl;
  }
  
  return 0; 
}
  // } Driver Code Ends
