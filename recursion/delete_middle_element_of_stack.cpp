#include <bits/stdc++.h>
using namespace std;


void solve(stack<int>&(st),int k){
    if(k==1){
        st.pop();
    }
    else{
        int temp = st.top();
        st.pop();
        solve(st,k-1);
        st.push(temp);
    }
}
void print_stack(stack<int>&(st)){
    if(st.empty())
        return;
    int temp = st.top();
    st.pop();
    print_stack(st);
    cout<<temp<<" ";


}
int main()
{
    stack <int> st;
    int input,n=10;
    for (int i=0;i<10;i++) {
        cin>>input;
        st.push(input);
    }
    solve(st,4);
    print_stack(st);
    cout<<endl;
    return 0;
}
