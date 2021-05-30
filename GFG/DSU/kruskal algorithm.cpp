// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    int find(int a,int arr[]){
        if(a==arr[a]){
            return a;
        }
        arr[a]=find(arr[a],arr);
        return arr[a];
    }
    
    //Function to merge two nodes a and b.
    void unionNodes( int a, int b, int arr[], int rank1[], int n) 
    {
        int x_rep = find(a,arr), y_rep=find(b,arr);
        if(rank1[x_rep]>rank1[y_rep]){
            arr[y_rep]=x_rep;
        }
        else if(rank1[x_rep]<rank1[y_rep]){
            arr[x_rep]=y_rep;
        }
        else{
            arr[y_rep]=x_rep;
            rank1[x_rep]++;
        }
    }
    
    //Function to determine number of connected components.
    int findNumberOfConnectedComponents( int n, int arr[], int rank1[]) 
    {
        int ans=0;
        for(int i=1;i<=n;i++){
            //cout<<arr[i]<<" ";
            if(i==arr[i]){
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.



int main() {
    int t;
    cin>>t;

    while(t--) {
        
        //taking number of nodes
        int n;
        cin>>n;

        //initializing parent array and
        //rank array
        for(int i=1; i<=n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        //taking number of queries
        int q;
        cin>>q;
        Solution obj;
        while(q--) {
            int a,b;
            cin>>a>>b;
            
            //calling unionNodes() function
            obj.unionNodes(a,b, arr, rank1, n);
        }

        //calling function findNumberofConnectedComponents()
        cout<<obj.findNumberOfConnectedComponents(n, arr, rank1)<<endl;
    }
    return 0;
}  // } Driver Code Ends
