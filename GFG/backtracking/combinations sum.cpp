// { Driver Code Starts
/*
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.
*/


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution 
{
    public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> s;
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        vector<int> curr;
        vector<vector<int>> res;
        sum(A,B,curr,res,0);
        return res;
    }
    void sum(vector<int> &A, int B,vector<int> &curr,vector<vector<int>> &res, int k) {
        if(B==0){
            res.push_back(curr);
            return;
        }
        for(int i=k;i<A.size() && B-A[i]>=0;i++){
            curr.push_back(A[i]);
            sum(A,B-A[i],curr,res,i);
            curr.pop_back();
        }
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
}	  // } Driver Code Ends
