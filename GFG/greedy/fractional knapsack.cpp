// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> wt;
        for(int i=0;i<n;i++){
            wt.push_back({(double)arr[i].value/arr[i].weight,i});
        }
        double ans=0;
        sort(wt.rbegin(),wt.rend());
        for(int i=0;i<n;i++){
            if(arr[wt[i].second].weight <= W){
                ans += arr[wt[i].second].value;
                W-=arr[wt[i].second].weight;
            }
            else{
                ans += arr[wt[i].second].value*(W/(double)arr[wt[i].second].weight);
                return ans;
            }
        }
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
