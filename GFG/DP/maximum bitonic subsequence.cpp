#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> lis,lds,a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
        int p = upper_bound(a.begin(),a.end(),x)-a.begin();
        if(p<a.size()){
            a[p]=x;
        }
        else{
            a.push_back(x);
        }
        lis.push_back(a.size());
    }
    a.clear();
    for(int i=n-1;i>=0;i--){
        int p = upper_bound(a.begin(),a.end(),b[i])-a.begin();
        if(p<a.size()){
            a[p]=b[i];
        }
        else{
            a.push_back(b[i]);
        }
        lds.push_back(a.size());
    }
    int res=-1;
    reverse(lds.begin(),lds.end());
    for(int i=0;i<n;i++){
        res=max(res,lds[i]+lis[i]-1);
        cout<<lis[i]<<" "<<lds[i]<<"\n";
    }
    cout<<res<<"\n";
}

int main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }

}
