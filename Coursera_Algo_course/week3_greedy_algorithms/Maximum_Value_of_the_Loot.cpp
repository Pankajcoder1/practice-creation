/*
    written by Pankaj Kumar.
    country:-INDIA
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<ll,ll> ml;
typedef set<char>sc;
typedef set<ll> sl;
#define pan cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
// define values.
// #define mod 1000000007
#define phi 1.618
/* Bit-Stuff */
#define get_set_bits(a) (__builtin_popcount(a))
#define get_set_bitsll(a) ( __builtin_popcountll(a))
#define get_trail_zero(a) (__builtin_ctz(a))
#define get_lead_zero(a) (__builtin_clz(a))
#define get_parity(a) (__builtin_parity(a))
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

bool compare(const pair<double,double>& x,const pair<double,double>& y)
{
	return x.ss>y.ss;
}

int main()
{
	ll n,q;
	cin>>n>>q;
	cout<<fixed<<setprecision(4);
	double a,b;
	double sum=0.0;
	vector<pair<double,double>> v(n);
	vector<pair<ll,double>> values(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a>>b;
		v[i]={a,b};
		a=double(a/b);
		values[i]={i,a};
	}
	sort(values.begin(),values.end(),compare);
	for(ll i=0;i<n;i++)
	{
		// cout<<values[i].ff<<" "<<values[i].ss<<endl;
		ll pos=values[i].ff;
		if(q>=v[pos].ss)
		{
			q-=v[pos].ss;
			sum+=v[pos].ff;
			// cout<<"added sum is "<<v[pos].ff<<endl;
		}
		else
		{
			double ans_temp=double((v[pos].ff)/(v[pos].ss))*q;
			// cout<<"ans added is "<<ans_temp<<endl;
			sum+=ans_temp;
			q=0;
		}
	}
	cout<<sum<<endl;
}