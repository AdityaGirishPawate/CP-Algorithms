// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends



#define ll long long

//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool issafe(int i,int j, int n, int m){
    return (i>=0 && i<n && j>=0 &&j<m);
}
long long solve(int N, int M)
{
    ll a1=N*M;
    ll a2=(a1*(a1-1));
    int t1[]={2,-2,2,-2};
    int t2[]={1,1,-1,-1};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++){
                if(issafe(i+t1[k],j+t2[k],N,M)){
                    a2--;
                }
                if(issafe(i+t2[k],j+t1[k],N,M)){
                    a2--;
                }
            }
        }
    }
    return a2%((int)1e9+7);
}
