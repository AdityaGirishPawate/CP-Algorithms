// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> ans;
	    bool visited[V];
	    for(int i=0;i<V; i++){
	        visited[i]=false;
	    }
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            vector<int>temp = dfs(adj, i, visited);
	            ans.insert(ans.end(),temp.begin(),temp.end());
	        }
	    }
	    return ans;
	}
	vector<int> dfs(vector<int> adj[], int u, bool visited[]){
	    vector<int> ans;
	    ans.push_back(u);
	    visited[u]=true;
	    for(auto v:adj[u]){
	        if(!visited[v]){
	            vector<int> temp = dfs(adj, v, visited);
	            ans.insert(ans.end(), temp.begin(), temp.end());
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
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
