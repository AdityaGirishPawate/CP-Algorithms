// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    long long tot=0;
    string ans;
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        ans = str;
        permute(str,0,str.size(),k);
        return ans;
        
    }
    void permute(string str,int l,int r,int k){
        if(l==r || tot==k){
            if(str>ans){
                ans=str;
            }
            return;
        }
        else{
            char curr=str[l];
            vector<int> ind;
            for(int i=l;i<=r;i++){
                if(str[i]>=curr){
                    curr=str[i];
                }
            }
            for(int i=l;i<=r;i++){
                if(str[i]==curr){
                    ind.push_back(i);
                }
            }
            for(auto ele:ind){
                swap(str[l],str[ele]);
                if(str[l]!=str[ele])
                    tot++;
                permute(str,l+1,r,k);
                swap(str[ele],str[l]);
                if(str[l]!=str[ele])
                    tot--;
            }
            
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
