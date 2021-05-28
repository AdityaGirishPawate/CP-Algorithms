#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PII pair<int,int>
void solve(){
    int n;
    cin>>n;
    vector<PII> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(),v.end());
    int ans=1,p=v[0].first;
    for(int i=1;i<n;i++){
        if(v[i].second>p){
            ++ans;
            p=v[i].first;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
