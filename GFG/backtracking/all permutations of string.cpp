#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32

//permutations of a string

void permute(string s,int i){
    if(i==s.size()){
        cout<<s<<"\n";
        return;
    }
    else{
        for(int j=i;j<s.size();j++){
            swap(s[i],s[j]);
            permute(s,i+1);
            swap(s[i],s[j]);
        }
    }
}


void solve(){
    string s;
    cin>>s;
    permute(s,0);
}

int main(){
  
  int t;
  cin >> t;
  
  while(t--){
    
    solve();
    
  }
  
  return 0;
}
