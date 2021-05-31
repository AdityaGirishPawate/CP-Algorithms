// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    queue<int> q;
	    bool visited[V];
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        visited[i]=false;
	    }
	    visited[0]=true;
	    q.push(0);
	    while(!q.empty()){
	        int temp=q.front();
	        ans.push_back(temp);
	        q.pop();
	        for(auto v:adj[temp]){
	            if(!visited[v]){
	                visited[v]=true;
	                q.push(v);
	            }
	        }
	    }
	   return ans; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
