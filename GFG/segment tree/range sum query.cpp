// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

ll *constructST(int *arr, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

ll getsum(ll *st, int n, int l, int r);
void updateValue(int *, ll *, int, int, int);

// Position this line where user code will be pasted

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num, query;
        cin >> num >> query;
        int arr[num];
        for (int i = 0; i < num; i++) cin >> arr[i];

        ll *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--) {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                cout << getsum(st, num, L, R) << endl;
            } else {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }

    return 0;
}
// } Driver Code Ends


// User function template for C++

// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree

//Function to update a value in input array and segment tree.
ll get(ll qs, ll qe, ll ss, ll se, ll *st, ll ind){
    if( ss>qe || qs>se ) return 0;
    if(ss>=qs && se<=qe){
        return st[ind];
    }
    ll mid = (ss+se)/2;
    return get(qs, qe, ss, mid,st,2*ind+1) + get(qs, qe, mid+1, se, st, 2*ind+2);
}

void update(ll *st, ll ss, ll se, int i, int ind, ll diff){
    if(ind<ss || ind>se)    return;
    if(ss==se){
        st[i]=diff;
        return;
    }
    int mid=(ss+se)/2;
    if(ind<=mid){
        update(st,ss,mid,2*i+1,ind,diff);
    }
    else{
        update(st,mid+1,se,2*i+2,ind,diff);
    }
    st[i]=st[2*i+1]+st[2*i+2];
}

void updateValue(int *arr, ll *st, int n, int index, int new_val) 
{
    arr[index]=new_val;
    update(st,0,n-1,0,index,new_val);
}

//Function to return sum of elements in range from index qs (query start)
//to qe (query end).
ll getsum(ll *st, int n, int l, int r)
{
    return get(l,r,0,n-1,st,0);
}
