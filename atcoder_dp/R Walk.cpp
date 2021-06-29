#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18+10

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#define pii pair<int,int>

void add_self(ll &a, ll b){
    a += b;
    if(a>=MOD){
        a-=MOD;
    }
}
void sub_self(ll &a, ll b){
    a -= b;
    if(a<0){
        a+=MOD;
    }
}
vector<vector<int>> adj;
vector<bool> vis;

ll mul(ll a, ll b){
    return (ll)a*b%MOD;
}

void max_self(ll &a, ll b){
    a = max(a,b);
}
int n;
struct M{
    vector<vector<ll>> t;
    explicit M(){
        t.assign(n,vector<ll>(n));
    }
    M operator* (const M& b) const {
        M c = M();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    add_self(c.t[i][j],mul(t[i][k],b.t[k][j]));
                }
            }
        }
        return c;
    }
};

void solve(){
    ll k;
    cin>>n>>k;
    M mat = M();
    for(int i=0;i<n;i++){
        for (int j = 0; j <n; ++j) {
            cin>>mat.t[i][j];
        }
    }
    M answer = M();
    for(int i=0;i<n;i++){
        answer.t[i][i]=1;
    }
    while(k>0){
        if(k&1) answer = (answer*mat);
        mat = mat*mat;
        k>>=1;
    }
    ll total=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            add_self(total,answer.t[i][j]);
        }
    }
    cout<<total<<"\n";
}


int main(){
    fastio();
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
