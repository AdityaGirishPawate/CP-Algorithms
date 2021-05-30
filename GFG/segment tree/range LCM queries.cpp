// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void updateValue(int *, ll *, int, int, int);
ll getLCM(ll *, int *, int, int, int);

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

ll LCM(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);

    st[si] = LCM(st[si * 2 + 1], st[si * 2 + 2]);
    return st[si];
}
ll *constructST(int *arr, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

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
            //  cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                cout << getLCM(st, arr, num, L, R) << endl;
            } else if (type == 'U') {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }
}// } Driver Code Ends


// User function template in C++

// arr : given array
// n : size of the array
// qs and qe are L and R respectively given in the problem to denotes range
// st : segment tree of the array arr


//Function to find LCM of given range.

ll gcd(ll a,ll b){
    if(a>b){
        swap(a,b);
    }
    if(a==0) return b;
    return gcd(a,b%a);
}


ll getLCM(ll *st, int qs,int qe,int ss,int se,int c){
    if(ss>qe || se < qs){
        return 1LL;
    }
    if(qs<=ss && qe>=se){
        return st[c];
    }
    ll mid = (ss+se)/2;
    ll a=getLCM(st,qs,qe,ss,mid,2*c+1);
    ll b=getLCM(st,qs,qe,mid+1,se,2*c+2);
    return LCM(a,b);
}

ll getLCM(ll *st, int *arr, int n, int qs, int qe) 
{
    return getLCM(st,qs,qe,0,n-1,0);
}

void updateValue(ll *st, int index, int new_val, int ss, int se, int c){
    if(ss>index || se<index){
        return;
    }
    if(ss==se){
        st[c]=new_val;
        return;
    }
    ll mid = (ss+se)/2;
    if(index<=mid){
        updateValue(st,index,new_val,ss,mid,2*c+1);
    }
    else{
        updateValue(st,index,new_val,mid+1,se,2*c+2);
    }
    st[c] = LCM(st[2*c+1],st[2*c+2]);
}

//Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    arr[index]=new_val;
    updateValue(st,index,new_val,0,n-1,0);
}











