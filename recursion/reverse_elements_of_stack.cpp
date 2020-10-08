#include <bits/stdc++.h>
using namespace std;


void Insert(stack<int>&(st),int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int temp=st.top();
    st.pop();
    Insert(st,element);
    st.push(temp);
}

void Reverse(stack<int>&(st)){
    if(st.size()==1){
        return;
    }
    int temp=st.top();
    st.pop();
    Reverse(st);
    Insert(st,temp);

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
    Reverse(st);
    print_stack(st);
    cout<<endl;
    return 0;
}
