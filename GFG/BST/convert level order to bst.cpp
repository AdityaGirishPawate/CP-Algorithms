// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    queue<pair<Node*,pair<int,int>>> q;
    int i=0;
    Node* head=new Node(arr[i++]);
    q.push({head,{INT_MIN,INT_MAX}});
    Node* temp = new Node(arr[i++]);
    while(!q.empty() && i<=n){
        Node* prev = q.front().first;
        int data=q.front().first->data;
        int l=q.front().second.first;
        int r=q.front().second.second;
        q.pop();
        if(temp->data > l && temp->data < data){
           prev->left = temp;
           q.push({temp,{l,data}});
           temp = new Node(arr[i++]);
        }
        if(temp->data > data && temp->data<r){
            prev->right = temp;
           q.push({temp,{data,r}});
           temp = new Node(arr[i++]);
        }
    }
    return head;
}
