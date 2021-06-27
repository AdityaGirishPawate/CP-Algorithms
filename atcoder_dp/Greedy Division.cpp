/*
Problem https://atcoder.jp/contests/agc054/tasks/agc054_b


*/

//Date -> 27-06-2021
//Atcoder Grand Contest
#include <bits/stdc++.h>
using     namespace     std;
typedef   long long     ll;
typedef   vector<int>   vi;
typedef   pair<int,int> pii;
#define   all(x)        (x).begin(),(x).end()
#define   rep(i,a,b)    for(ll i = a; i<b ; i++)
#define   sz(x)         (int)((x).size())
#define   PI             3.141592653589
#define   mod            998244353//1000000007 
#define   MAX            1000005 //1e6+5
#define   ppc             __builtin_popcount
#define   ppcll           __builtin_popcountll
long long const INF = 1e6;
 
ll power(ll a, ll b) 
{   ll result =1;
    while(b)
    {   if(b%2) result=(result*a)%mod;    
        a=(a*a)%mod;
        b/=2;}
    return result;
}
/*
Let X = T(Takahashi's Score) — A(Aoki's score)
 
Initially, X = 0 The process is such that, at the first step, some w[i] will be added to X, then for the next 
few steps 2,3,4... etc some w[i]'s shall be subtracted and finally the sum becomes 0, at the last step.
 
So, there are some k elements which are added to X, and some n — k elements which are subtracted from X, 
so that X remains 0 finally, after the process.
 
Let us say we have already chosen these elements: We have some k elements if the W array,
 whose sum is exactly equal to the remaining n — k elements.
 
The k elements will give positive contribution to X, and n — k will give negative contribution.
 
Once the elements are chosen, at the first step, the element kept shall be one of the k elements 
(as first step is a positive contribution.Then, the next element must be from the 
other group (with n — k elements), it can be chosen in (n — k) ways, if the sum is still > 0,
then again some element will be chosen from the 2nd (negative contribution group) group, 
this time with (n — k — 1) possibilities... next maybe (n — k — 2) possibilities and so on,
until X becomes < 0, now out of the (k-1) elements of the first group, some will be chosen 
(of course in k-1 ways..)
 
Basically, the above should kind of show that once k elements 
with "positive role" and n — k with "negative role" are chosen, 
then we can take them individually in any order. 
I mean the elements of a particular group can be permuted with each other. So, (n — k)! * k! ways are there.*/
int n;
int a[102];
ll fact[104];
void sol()
{
    cin>>n;
    int sum =0;
    rep(i,0,n) {cin>>a[i]; sum+=a[i];}
    fact[0]=1;
    for(int i=1;i<102;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
 
    if(sum%2 != 0) {cout<<"0"; return;}
    int req = sum/2;
 
    ll dp[n+1][req+1]; //dp[k][x] is num of way making sum x using exactly k elemnts
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=0;i<n;i++) //indices
    {
        //length 
        for(int j=i;j>=0;j--) 
        {
            //sum
            for(int s=0;s<=j*100;s++) 
            {
                if(s+a[i]<=req){
                    dp[j+1][s+a[i]] += dp[j][s];          //PUSH DP
                    dp[j+1][s+a[i]]%=mod;
                }
            }
        }
    }
    ll ans = 0;
    for(int k=1;k<=n-1;k++)
    {
        ll curr = ((fact[k]*fact[n-k])%mod)*dp[k][req]; 
        curr%=mod;
        ans = ans + curr;
        ans%=mod;
    }
    cout<<ans;
}
int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    int T=1; //cin>>T;
    while(T--) sol();
    return 0;
}
