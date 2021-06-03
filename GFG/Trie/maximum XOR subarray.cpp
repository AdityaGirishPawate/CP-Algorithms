// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32


 // } Driver Code Ends
//User function template for C++

// arr : given array
// n : size of the given array

class Solution
{
    public:
    //Function to return maximum XOR value.
    struct Node{
        int data;
        Node* child[2];
        Node(int x){
            data=x;
            child[0]=NULL;
            child[1]=NULL;
        }
    };
    void insert(int x,Node* root){
        Node* temp=root;
        for(int i=30;i>=0;i--){
            int curr=(x>>i)&1;
            if(curr==1){
                if(temp->child[1]==NULL){
                    temp->child[1] = new Node(1);
                    temp=temp->child[1];
                }
                else{
                    temp=temp->child[1];
                }
            }
            else{
                if(temp->child[0]==NULL){
                    temp->child[0]=new Node(0);
                    temp = temp->child[0];
                }
                else{
                    temp = temp->child[0];
                }
            }
        }
    }
    int find(Node* root,int pre[],int n){
        int ans=0;
        for(int i=0;i<n;i++){
            Node* curr=root;
            int x=pre[i];
            int m=pow(2,30);
            int cx = 0;
            for(int j=30;j>=0;j--){
                int val = (x>>j)&1; 
                if(val==1){
                    if(curr->child[0]!=NULL){
                        cx+=m;
                        curr=curr->child[0];
                    }
                    else{
                        curr=curr->child[1];
                    }
                }
                else{
                    if(curr->child[1]!=NULL){
                        cx+=m;
                        curr=curr->child[1];
                    }
                    else{
                        curr=curr->child[0];
                    }
                }
                m>>=1;
            }
            ans=max(ans,cx);
        }
        return ans;
    }
    
    
    int maxSubarrayXOR(int arr[], int n)
    {
        int pre[n+1];
        pre[0]=0;
        Node* root=new Node(0);
        insert(pre[0],root);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]^arr[i-1];
            insert(pre[i],root);
        }
        return find(root,pre,n+1);
    }
};



// { Driver Code Starts.

int main(){
  
  int t;
  cin >> t;
  
  while(t--){
    
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0;i<n;i++){
      cin >> arr[i];
    }
    Solution obj;
    cout << obj.maxSubarrayXOR(arr, n) << endl;
    
  }
  
  return 0;
}  // } Driver Code Ends
