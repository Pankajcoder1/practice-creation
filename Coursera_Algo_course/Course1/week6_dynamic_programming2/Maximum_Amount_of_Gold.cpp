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
    ll w,n;
    cin>>w>>n;
    vl v(n+1,0);
    for(ll i=1;i<=n;i++) cin>>v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(w+1));
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=w;j++)
        {
            if(i==0||j==0) dp[i][j]=0;
            else if(v[i]<=j)
            {
                dp[i][j]=max((v[i]+dp[i-1][j-v[i]]),dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}

int main()
{
    //freopen("input.txt"a, "r", stdin);
    pan;
    solve();
    return 0;
}

/* stuff you should look before submission 
* int overflow
* special test case (n=0||n=1||n=2)
* don't get stuck on one approach if you get wrong answer
*/