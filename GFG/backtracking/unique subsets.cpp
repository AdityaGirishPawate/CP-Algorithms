// { Driver Code Starts
/*
Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.
Note: Each subset should be sorted.
*/


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


#define ll long long
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        set<vector<int>> st;
        vector<vector<int>> res;
        vector<int> curr;
        ll p=pow(2,n);
        for(int i=0;i<p;i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    curr.push_back(arr[j]);
                }
            }
            st.insert(curr);
            curr.clear();
        }
        for(auto k:st){
            res.push_back(k);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends
