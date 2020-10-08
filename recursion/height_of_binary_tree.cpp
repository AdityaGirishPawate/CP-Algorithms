#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<graphics.h>
using namespace std;

typedef struct node{
    int value;
    struct node* right;
    struct node* left;
}NODE;

int find_height(NODE* a){
    if(a == nullptr)
        return 0;
    else
        return max(find_height(a->left)+1,find_height(a->right)+1);
}

int main()
{
    NODE a,b,c,d,e,f;
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = nullptr;
    c.left = nullptr;
    c.right = nullptr;
    d.left = &e;
    d.right = nullptr;
    e.right = &f;
    e.left = nullptr;
    f.right = nullptr;
    f.left =nullptr;
    cout<<find_height(&b)<<endl;
    return 0;
}
