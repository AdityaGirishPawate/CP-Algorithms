// { Driver Code Starts
/*
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.


bool coloring(bool graph[101][101], int m, int V, int color[]){
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            for(int k=0;k<m;k++){
                bool ok=1;
                for(int j=0;j<V;j++){
                    if(graph[i][j]==1 && color[j]==k){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    color[i]=k;
                    if(coloring(graph,m,V,color)==false){
                        color[i]=-1;
                        continue;
                    }
                }
            }
        }
        if(color[i]==-1){
            return false;
        }
    }
    return true;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V];
    fill(color,color+V,-1); 
    return coloring(graph,m,V,color);
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
