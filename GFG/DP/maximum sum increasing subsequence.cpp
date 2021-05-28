#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PII pair<int,int>
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int msis[n],ans=-1;
    for(int i=0;i<n;i++) {
        msis[i] = v[i];
        for (int j = 0; j < i; j++){
            if(v[i]>v[j]){
                msis[i]=max(msis[i],v[i]+msis[j]);
                ans=max(msis[i],ans);
            }
        }
    }
    cout<<ans;
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
