// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=A[0];
        dp[0][1]=0;
        int msf=A[0],c=A[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max({A[i],dp[i-1][0]+A[i]});
            dp[i][1] = max({dp[i-1][1]+A[i],A[i],dp[i-1][0]});
            msf = max({dp[i][1],dp[i][0],msf});
        }
        return msf;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		Solution obj;
		cout<<obj.maxSumSubarray(a,n)<<endl;
	}
}

  // } Driver Code Ends
