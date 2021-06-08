// { Driver Code Starts
/*A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long mod=(long long)1e9+7;
    long long countWays(int n)
    {
        long long f=1,s=2,t=4;
        if(n==1){
            return f;
        }
        if(n==2){
            return s;
        }
        if(n==3){
            return t;
        }
        for(long long i=4;i<=n;i++){
            long long temp = ((t)%mod+(s)%mod+(f)%mod)%mod;
            f=s%mod;
            s=t%mod;
            t=temp%mod;
        }
        return t%mod;
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends
