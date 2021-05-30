// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int getMid(int s, int e) {  return s + (e -s)/2;  }

void constructSTUtil(int *arr, int ss, int se, PII *st, int si)
{
    if (ss == se)
    {
        st[si].first = st[si].second = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si*2+1);
    constructSTUtil(arr, mid+1, se, st, si*2+2);
    
    st[si].first = min(st[si*2+1].first, st[si*2+2].first);
    st[si].second = max(st[si*2+1].second, st[si*2+2].second);
    
    return;
}

PII *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    PII *st = new PII[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

void updateValue(int *, PII *, int, int, int);
PII getMinMax(PII *, int *, int, int, int);

// Position this line where user code will be pasted

int main(){
	int t;
	cin>>t;
	while(t--){
		int num, query;
		cin>>num>>query;
		int arr[num];
		for(int i=0;i<num;i++)
			cin>>arr[i];
		
		PII *st = constructST(arr, num);
		int L, R, index , val;
		char type;
		while(query--){
		    cin.ignore(INT_MAX, '\n');
		    cin>>type;
		    if(type == 'G'){
		        cin>>L>>R;
		        PII ans = getMinMax(st, arr, num, L, R);
		        cout<<ans.first<<" "<<ans.second<<endl;
		    }
		    else{
		        cin>>index>>val;
		        updateValue(arr, st, num, index, val);
		    }
		    
		}	
	}
	return 0;
}
// } Driver Code Ends


//User function template for C++

// arr : given array arr
// st : segment tree of the given array arr
// n :  size of arr array
// qs and qe : index range to find Min and Max value between these indexes.
// PII :  return pair denoting min,max respectively.
// index : given index to update with new_val

PII getMinMax(PII *st,int qs,int qe,int ss, int se, int curr){
    if(se<qs || qe<ss){
        return {INT_MAX,INT_MIN};
    }
    if(qs<=ss && qe>=se){
        return st[curr];
    }
    int mid=(ss+se)/2;
    PII x=getMinMax(st,qs,qe,ss,mid,2*curr+1);
    PII y=getMinMax(st,qs,qe,mid+1,se,2*curr+2);
    return {min(x.first,y.first),max(x.second,y.second)};
}

PII getMinMax(PII *st, int *arr, int n, int qs, int qe)
{
    return getMinMax(st,qs,qe,0,n-1,0);
}

void updateValue(PII *st,int index, int new_val, int ss,int se,int curr){
    if(index>se || index<ss){
        return;
    }
    if(ss==se){
        st[curr]={new_val,new_val};
        return;
    }
    int m=(ss+se)/2;
    if(index<=m){
        updateValue(st,index,new_val,ss,m,2*curr+1);
    }
    else{
        updateValue(st,index,new_val,m+1,se,2*curr+2);
    }
    st[curr] = {min(st[2*curr+1].first,st[2*curr+2].first),max(st[2*curr+1].second,st[2*curr+2].second)};
}

void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
   arr[index]=new_val;
   updateValue(st,index,new_val,0,n-1,0);
}







