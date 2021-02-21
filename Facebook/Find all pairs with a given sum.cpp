// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int k);

int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int n, m, k;
	    cin >> n >> m >> k;
        int a[n], b[m];
        
	    for(int i = 0;i<n;i++)
	        cin >> a[i];
	    for(int i = 0;i<m;i++)
	        cin >> b[i];
	        
	   vector<pair<int,int>> vp = allPairs(a, b, n, m, k);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}// } Driver Code Ends


vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int k)
{
    unordered_map<int,int> ump;
    vector<pair<int,int>> ans;
    sort(a,a+n);
    for(int i=0;i<m;i++){
        ump[b[i]]++;
    }
    for(int i=0;i<n;i++){
        if(ump[k-a[i]]>=1){
            ans.push_back({a[i],k-a[i]});
        }
    }
    return ans;
}
