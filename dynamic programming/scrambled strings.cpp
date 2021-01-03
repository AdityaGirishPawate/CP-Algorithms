#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5

bool is_scrambled(const string& a,const string& b,int i,int j){
    if(a.size()!=b.size())  return false;
    if(a.size()==1){
        return a==b;
    }
    else{
        bool ans=false;
        for (int k = 0; k < a.size()-1; ++k) {
            bool lf1, lf2, rf1, rf2, lf, rf;
            lf1 = is_scrambled(a.substr(0, k + 1), b.substr(0, k + 1), i, k);
            lf2 = is_scrambled(a.substr(0, k + 1), b.substr(b.size() - k - 1, k + 1), i, k);
            rf1 = is_scrambled(a.substr(k + 1, a.size() - k - 1), b.substr(k + 1, b.size() - k - 1), k + 1, j);
            rf2 = is_scrambled(a.substr(k+1,a.size()-k-1),b.substr(0,b.size()-k-1), k+1,j);
            if(lf1&&rf1 || lf2&&rf2){
                ans=true;
                break;
            }
        }
        return ans;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    if(is_scrambled(a,b,0,a.size())){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

