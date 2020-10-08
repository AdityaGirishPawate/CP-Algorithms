#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define int long long

void solve(vector<int>(in),vector<int>(out)){
    if(in.empty()){
        cout<<"{ ";
        f(i,0,out.size()){
            cout<<out[i]<<", ";
        }
        cout<<" }"<<endl;
        return;
    }
    vector<int> op1=out;
    vector<int> op2=out;
    op2.push_back(in[0]);
    in.erase(in.begin());
    solve(in,op1);
    solve(in,op2);

}
int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n),b;
    for(auto &k:a){
        cin>>k;
    }
    solve(a,b);
    return 0;
}
