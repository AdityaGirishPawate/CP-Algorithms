// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends





//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
bool issafe(vector<int> maze[],int l,int r, int N){
    return ( (l<N && r<N && maze[l][r]!=0) || (l==N-1 &&r==N-1));
}
bool ans(vector<int> maze[],int l,int r, vector<vector<int>> &grid, int N){
    if(l==N-1 && r==N-1) return true;
    for(int i=1;i<=maze[l][r];i++){
        if(issafe(maze,l,r+i,N)){
            grid[l][r+i]=1;
            if(ans(maze,l,r+i,grid,N)==true){
                return true;
            }
            grid[l][r+i]=0;
        }
        if(issafe(maze,l+i,r,N)){
            grid[l+i][r]=1;
            if(ans(maze,l+i,r,grid,N)==true){
                return true;
            }
            grid[l+i][r]=0;
        }
    }
    return false;
}
void print(vector<vector<int>> grid,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void solve(int N, vector<int> maze[]) 
{
    vector<vector<int>> grid(N,vector<int>(N,0));
    grid[0][0]=maze[0][0];
    if(ans(maze,0,0,grid,N)==false){
        cout<<-1<<"\n";
    }
    else{
        print(grid,N);
    }
}
