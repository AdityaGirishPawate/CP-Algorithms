#include <cstdio>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;
#define int long long
#define INF (int)10e9
#define MAX_INT (int)10e5+5


int32_t main() {
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    bool p[s.size()][s.size()];
    int c[s.size()];
    for (int i = 0; i < s.size(); ++i) {
        p[i][i]=true;
    }
    for (int l = 2; l <= s.size(); ++l) {
        for (int i = 0; i < s.size()-l+1; ++i) {
            int j=i+l-1;
            if(l==2){
                p[i][j] = (s[i]==s[j]);
            }
            else{
                p[i][j] = (s[i]==s[j])&&(p[i+1][j-1]);
            }
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if(p[0][i]){
            c[i]=0;
        }
        else{
            c[i]=INT_MAX;
            for (int j = 0; j < i; ++j) {
                if(p[j+1][i])
                    c[i] = min(c[i],c[j]+1);
            }
        }
    }
    cout<<c[s.size()-1]<<endl;
    return 0;
}

