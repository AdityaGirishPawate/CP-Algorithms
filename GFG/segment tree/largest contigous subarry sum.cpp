// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Structure of node of the tree
struct node {
	int sum, prefixsum, suffixsum, maxsum;
};

// A Max of 1000 Node Array
node tree[4 * 1000];

// Utility funciton to build the tree
void build(int arr[], int low, int high, int index)
{
	if (low == high) {
		tree[index].sum = arr[low];
		tree[index].prefixsum = arr[low];
		tree[index].suffixsum = arr[low];
		tree[index].maxsum = arr[low];
	} else {
		int mid = (low + high) / 2;
		build(arr, low, mid, 2 * index + 1);
		build(arr, mid + 1, high, 2 * index + 2);
		tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;
		tree[index].prefixsum = max(tree[2 * index + 1].prefixsum, tree[2 * index + 1].sum + tree[2 * index + 2].prefixsum);
		tree[index].suffixsum = max(tree[2 * index + 2].suffixsum, tree[2 * index + 2].sum + tree[2 * index + 1].suffixsum);
		tree[index].maxsum = max(tree[index].prefixsum, max(tree[index].suffixsum, max(tree[2 * index + 1].maxsum, max(tree[2 * index + 2].maxsum,tree[2 * index + 1].suffixsum + tree[2 * index + 2].prefixsum))));
	}
}

// Your task is to complete this function
// function should update the array and as Tree as well accordingly
void update(int arr[], int arrSize, int index, int value);

// Your task is to complete this function
// funciton should return the Max-Sum in the range
int query(int arr[], int arrSize, int l, int r);

// Driver Code
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	    int n, q, index, value, left, right, type;
	    int* arr = NULL;
	    cin>>n>>q;
	    arr = new int[n];
	    for(int i=0; i<n; i++)cin>>arr[i];
	    build(arr, 0, n-1, 0);
	    for(int i=0; i<q; i++){
	        cin>>type;
	        if(type==1){
	            cin>>left>>right;
	            cout<<query(arr, n, left, right)<<endl;
	        } else {
	            cin>>index>>value;
	            update(arr, n, index, value);
	        }
	    }
	    delete [] arr;
	    arr = NULL;
	}
	return 0;
}

 // } Driver Code Ends
//User function Template for C++


//Function to update a value in input array and segment tree.
node merge(node x, node y){
    node ans;
    if(x.sum==INT_MIN){
        return y;
    }
    if(y.sum==INT_MIN){
        return x;
    }
    ans.sum = x.sum + y.sum;
    ans.prefixsum = max(x.prefixsum,x.sum+y.prefixsum);
    ans.suffixsum = max(y.suffixsum,y.sum+x.suffixsum);
    ans.maxsum = max({ans.prefixsum,ans.suffixsum,y.prefixsum+x.suffixsum,x.maxsum,y.maxsum});
    return ans;
}

node init(int v1, int v2,int v3,int v4){
    node ans;
    ans.sum=v1;
    ans.prefixsum = v2;
    ans.suffixsum= v3;
    ans.maxsum = v4;
    return ans;
}
void update(int index,int value,int ss,int se, int c){
    if(ss==se){
        tree[c] = init(value,value,value,value);
        return;
    }
    int mid=(ss+se)/2;
    if(index<=mid){
        update(index,value,ss,mid,2*c+1);
    }
    else{
        update(index,value,mid+1,se,2*c+2);
    }
    
    tree[c] = merge(tree[2*c+1],tree[2*c+2]);
}


void update(int arr[], int arrSize, int index, int value)
{
    update(index-1,value,0,arrSize-1,0);
}


//Funciton to return the Maximum-Sum in the range.
node query(int qs,int qe,int ss,int se,int c){
    if(qs>se || qe<ss){
        return init(INT_MIN,INT_MIN,INT_MIN,INT_MIN);
    }
    if(qs<=ss && qe>=se){
        return tree[c];
    }
    int mid=(ss+se)/2;
    node x = query(qs,qe,ss,mid,2*c+1);
    node y = query(qs,qe,mid+1,se,2*c+2);
    return merge(x,y);
}

int query(int arr[], int n, int l, int r) 
{
    node ans=query(l-1,r-1,0,n-1,0);
    return ans.maxsum;
}



// { Driver Code Starts.  // } Driver Code Ends
