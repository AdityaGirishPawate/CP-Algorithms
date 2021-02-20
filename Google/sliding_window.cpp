// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int arr[], int n, int s){
    vector<int> ans;
    int l=0,r=0,currsum=arr[0];
    while(true){
        while(currsum< s && r<n){
            r++;
            currsum += arr[r];
        }
        if(currsum==s){
            ans.push_back(l+1);
            ans.push_back(r+1);
            break;
        }
        while(currsum> s && l<n){
            currsum-= arr[l];
            l++;
        }
        if(currsum==s){
            ans.push_back(l+1);
            ans.push_back(r+1);
            break;
        }
        if(l>n-1 || r>n-1){
            ans.push_back(-1);
            break;
        }
    }
    return ans;
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int>res;
        res = subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
