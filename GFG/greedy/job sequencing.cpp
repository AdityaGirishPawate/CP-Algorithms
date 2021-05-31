// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
#define PII pair<int,int>
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    int find(int x,int par[]){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x],par);
    }
    
    void uni(int x, int y,int par[]){
        par[y]=x;
    }
    struct mycomp{
        bool operator()(PII a, PII b){
            return a.second > b.second;
        }
    };
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        int size=n;
        multiset<PII,mycomp> st;
        for(int i=0;i<n;i++){
            st.insert({arr[i].dead-1,arr[i].profit});
            size=max(arr[i].dead,size);
        }
        int par[size];
        iota(par,par+size,0);
        vector<int> ans(2,0);
        bool ok=1;
        for(auto it=st.begin();it!=st.end();it++){
            int x=find((*it).first,par);
            // cout<<x<<" "<<(*it).second<<"\n"; 
            if(x>0){
                ans[0]++;
                ans[1]+=(*it).second;
                uni(x-1,x,par);
            }
            else if(x==0 && ok){
                ans[0]++;
                ans[1]+=(*it).second;
                ok=0;
            }
        }
        return ans;
    } 
};






// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
