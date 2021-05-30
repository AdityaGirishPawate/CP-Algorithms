#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PII pair<int,int>

class bit{
public:
    int n;
    int *arr;
    explicit bit(int x){
        n=x;
        arr = new int[n+1];
        for(int i=0;i<=n;i++){
            arr[i]=0;
        }
    }
    void update(int i,int x) const{
        i+=1;
        while(i<=n){
            arr[i] += x;
            i= i + i&(-i);
        }
    }

    int prefix(int i) const{
        i=i+1;
        int res=0;
        while(i>0){
            res+=arr[i];
            i = i - (i & (-i));
            //cout<<i<<" ";
        }
        return res;
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    bit obj(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        obj.update(i,arr[i]);
        //cout<<obj.arr[i]<<" ";
    }
    for(int i=0;i<obj.n;i++){
        //obj.prefix(i);
        cout<<obj.prefix(i)<<" ";
    }

}

int main(){
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
