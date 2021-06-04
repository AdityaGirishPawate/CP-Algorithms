// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool issafe(int i,int j,int grid[N][N],int k){
        for(int p=0;p<N;p++){
            if(grid[i][p]==k || grid[p][j]==k){
                //cout<<"c1\n";
                return false;
            }
        }
        int i1=i-i%3,j1=j-j%3;
        for(int p1=0;p1<3;p1++){
            for(int p2=0;p2<3;p2++){
                if(grid[i1+p1][j1+p2]==k){
                    //cout<<"c2\n";
                    return false;
                }
            }
        }
        //cout<<"c3\n";
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int k=1;k<=N;k++){
                        if(issafe(i,j,grid,k)){
                            grid[i][j]=k;
                            if(SolveSudoku(grid)==false){
                                grid[i][j]=0;
                                continue;
                            }
                        }
                    }
                    if(grid[i][j]==0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
