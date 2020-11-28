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

int calc(int a,int b,char op)
{
	if(op=='*') return a*b;
	else if(op=='+') return a+b;
	else return a-b;
}

int main()
{
	ll n;
	string s;
	cin>>s;
	n=s.length()/2+1;
	vector<char> op;
	vector<ll> val;
	ll temp;
	char temp_;
	for(ll i=0;i<2*n+1;i++)
	{
		if(i%2==0)
		{
			val.push_back(ll(s[i])-48);
		}
		else
		{
			op.push_back(s[i]);
		}
	}
	
	vector<vector<vector<ll>>> arr(n,vector<vector<ll>>(n,vector<ll> (2)));
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i==j)
			{
				arr[i][j][0]=val[i];
				arr[i][j][1]=val[i];
			}
			else
			{
				arr[i][j][0]=INT_MAX;
				arr[i][j][1]=INT_MIN;
			}
		}
	}
	ll min_,max_;
	for(ll j=1;j<n;j++)
	{
		for(ll i=0;i<n-j;i++)
		{
			min_=INT_MAX;
			max_=INT_MIN;
			for(ll k=i;k<i+j;k++)
			{
				temp=calc(arr[i][k][0],arr[k+1][i+j][0],op[k]);
				min_=min(min_,temp);
				max_=max(max_,temp);
				temp=calc(arr[i][k][1],arr[k+1][i+j][0],op[k]);
				min_=min(min_,temp);
				max_=max(max_,temp);
				temp=calc(arr[i][k][0],arr[k+1][i+j][1],op[k]);
				min_=min(min_,temp);
				max_=max(max_,temp);
				temp=calc(arr[i][k][1],arr[k+1][i+j][1],op[k]);
				min_=min(min_,temp);
				max_=max(max_,temp);
				arr[i][i+j][0]=min(min_,arr[i][i+j][0]);
				arr[i][i+j][1]=max(max_,arr[i][i+j][1]);
			}
		}
	}
	cout<<arr[0][n-1][1]<<endl;
}