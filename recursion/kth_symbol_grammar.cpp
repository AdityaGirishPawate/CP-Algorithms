#include <bits/stdc++.h>
using namespace std;


bool solve(int n,int k){
    if(n==1 && k==1){
        return 0;
    }
    if(k<=pow(2,n-2)){
        return solve(n-1,k);
    }
    else{
        return !solve(n-1,k-(int)pow(2,n-2));
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
    return 0;
}
