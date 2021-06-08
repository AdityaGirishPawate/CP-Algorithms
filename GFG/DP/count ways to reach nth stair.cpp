// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod =(int)1e9+7;
    int countWays(int n)
    {
        int fib1=1,fib2=1;
        if(n==1)return 1;
        for(int i=2;i<=n;i++){
            int temp= (fib1%mod+fib2%mod)%mod;
            fib2=fib1%mod;
            fib1=temp%mod;
        }
        return fib1%mod;
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends
