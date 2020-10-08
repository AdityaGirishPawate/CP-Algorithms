#include <bits/stdc++.h>
using namespace std;


void toi(int n, char source, char inter, char dest){
        if(n==1){
            cout<<source<<" -> "<<dest<<endl;
            return;
        }
        toi(n-1,source,dest,inter);
        cout<< source <<" -> "<< dest<<endl;
        toi(n-1,inter,source,dest);
}
int main()
{
    int n;
    cin>>n;
    toi(n,'s','i','d');
    return 0;
}
