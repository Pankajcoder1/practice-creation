/*
    written by Pankaj Kumar.
    country:-INDIA
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef vector<ll> vl;
#define pan cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
// define values.
// #define mod 1000000007
#define phi 1.618
/*  Abbrevations  */
#define ff first
#define ss second
#define mp make_pair
#define line cout<<endl;
#define pb push_back
#define Endl "\n"
// loops
#define forin(arr,n) for(ll i=0;i<n;i++) cin>>arr[i];
// Some print
#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
#define cc ll test;cin>>test;while(test--)
// sort
#define all(V) (V).begin(),(V).end()
#define srt(V) sort(all(V))
#define srtGreat(V) sort(all(V),greater<ll>())
#define printv(v) for(ll i=0;i<ll(v.size());i++){cout<<v[i]<<" ";} line;
// function

ll power(ll x,ll y,ll mod)
{
    ll res=1;
    // x=x%mod;
    while(y>0)
    {
        if(y%2==1)
        {
            res*=x;
            // res=res%mod;
        }
        y/=2; x*=x; // x=x%mod;
    }
    return res;
}
// datatype definination
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

/* ascii value 
A=65,Z=90,a=97,z=122
*/
/*  -----------------------------------------------------------------------------------*/

ll solve()
{
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(0);
    int n;
    cin>>n;
    int min_;
    for(int i=2;i<=n;i++){
        min_=dp[i-1];
        if(i%3==0) min_=min(min_,dp[i/3]);
        if(i%2==0) min_=min(min_,dp[i/2]);
        dp.push_back(min_+1);
    }
    cout<<dp[n]<<endl;
    vector<int> result;
    result.push_back(n);
    int i=n;
    while(i>1){
        if(dp[i-1]==dp[i]-1) {
            result.push_back(i-1);
            i-=1;
        }
        else if(i%2==0 && dp[i/2]==dp[i]-1){
            result.push_back(i/2);
            i/=2;
        }
        else{
            result.push_back(i/3);
            i/=3;
        }
    }
    reverse(result.begin(),result.end());
    for(int i=0;i<result.size();i++) cout<<result[i]<<' ';
    return 0;
}

int main()
{
    pan;
    //freopen("input.txt"a, "r", stdin);
    solve();
}

/* stuff you should look before submission 
* int overflow
* special test case (n=0||n=1||n=2)
* don't get stuck on one approach if you get wrong answer
*/