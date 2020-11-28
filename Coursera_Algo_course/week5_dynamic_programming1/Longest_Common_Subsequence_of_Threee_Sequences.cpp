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

ll maxo=101LL;

ll solve()
{
    ll l,m,n;
    cin>>l;
    vl v1(l,0);
    forin(v1,l);
    cin>>m;
    vl v2(m,0);
    forin(v2,m);
    cin>>n;
    vl v3(n,0);
    forin(v3,n);
    vector<vector<ll>> dp1(maxo,vector<ll>(maxo)),dp2(maxo,vector<ll>(maxo)),dp3(maxo,vector<ll>(maxo));
    // for v1 and v2
    for(ll i=0;i<=l;i++)
    {
        for(ll j=0;j<=m;j++)
        {
            if(i==0||j==0) dp1[i][j]=0;
            else if(v1[i-1]==v2[j-1]) dp1[i][j]=dp1[i-1][j-1]+1;
            else dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
        }
    }

    // for v2 and v3
    for(ll i=0;i<=m;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            if(i==0||j==0) dp2[i][j]=0;
            else if(v2[i-1]==v3[j-1])
            {
                dp2[i][j]=1+dp2[i-1][j-1];
            }
            else dp2[i][j]=max(dp2[i-1][j],dp2[i][j-1]);
        }
    }

    // for v1 and v3
    for(ll i=0;i<=l;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            if(i==0||j==0) dp3[i][j]=0;
            else if(v1[i-1]==v3[j-1]) dp3[i][j]=1+dp3[i-1][j-1];
            else dp3[i][j]=max(dp3[i][j-1],dp3[i-1][j]);
        }
    }
    cout<<min({dp1[l][m],dp2[m][n],dp3[l][n]})<<endl;
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