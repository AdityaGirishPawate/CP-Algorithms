// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int find(int x, int arr[]){
        if(arr[x]==-1){
            return x;
        }
        arr[x] = find(arr[x],arr);
        return arr[x];
    }
    
    void union_dsu(int x, int y, int arr[], int rank[]){
        int x_rep=find(x,arr), y_rep=find(y,arr);
        if(rank[x_rep]>rank[y_rep]){
            arr[y_rep] = x_rep;
        }
        else if(rank[x_rep] < rank[y_rep]){
            arr[x_rep] = y_rep;
        }
        else{
            arr[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
    
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    //cout<<V<<"\n";
	    int rank[V],arr[V];
	    for(int i=0;i<V;i++){
	        arr[i] = -1;
	        rank[i] = 0;
	    }
	    set<pair<int,int>> st;
	    for(int i=0;i<V;i++){
	        //cout<<"Size "<<adj[i].size()<<"\n";
    	    for(auto ele:adj[i]){
    	        if(st.find({ele,i})==st.end()){
    	            st.insert({i,ele});
    	        }
    	    }
	    }
	    //cout<<st.size()<<"\n";
	    for(auto k:st){
	        if(find(k.first,arr)==find(k.second,arr)){
	            return 1;
	        }
    	   union_dsu(k.first,k.second,arr,rank);
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends
