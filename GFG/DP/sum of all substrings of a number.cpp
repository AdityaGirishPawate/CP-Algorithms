// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#define ll long long
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int n=s.size(),mod=(int)1e9+7;
        vector<ll> dp(n);
        dp[0]=s[0]-'0';
        ll sum=dp[0];
        for(int i=1;i<n;i++){
            dp[i] = (dp[i-1]*10 + (i+1)*(s[i]-'0'))%mod;
            sum+=dp[i]%mod;
        }
        return sum%mod;
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
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends
