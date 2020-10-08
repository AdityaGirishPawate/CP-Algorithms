#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<graphics.h>
using namespace std;

void Insert(stack<int>&(st), int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    if(element>=st.top()){
        st.push(element);
    }
    else{
        int temp=st.top();
        st.pop();
        Insert(st,element);
        st.push(temp);
    }
}

void Sort(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    Sort(st);
    Insert(st,ele);

}

int main()
{
    stack <int> st;
    int input;
    for (int i=0;i<10;i++) {
        cin>>input;
        st.push(input);
    }
    Sort(st);
    for (int i=0;i<10;i++) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
