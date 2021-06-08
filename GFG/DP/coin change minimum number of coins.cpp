// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Complete this function

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        long long dp[value+1][numberOfCoins+1];
        for(int i=0;i<=value;i++){
            dp[i][0]= INT_MAX;
        }
        for(int i=0;i<=numberOfCoins;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=value;i++){
            for(int j=1;j<=numberOfCoins;j++){
                if(i>=coins[j-1]){
                    dp[i][j] = min(dp[i][j-1], 1+dp[i-coins[j-1]][j]);
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        if(dp[value][numberOfCoins]==INT_MAX)
            return -1;
        else{
            return dp[value][numberOfCoins];
        }
    }
};

// { Driver Code Starts.



int main() {
	
	//taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function minimumNumberOfCoins()
	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
