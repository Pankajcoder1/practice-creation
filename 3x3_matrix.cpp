/*
    written by Pankaj Kumar.
    country:-INDIA
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef set<pair<int,int>> spi;
typedef set<pair<ll,ll>> spl;
typedef vector<pair<int,int>> vpi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pair<ll,ll>> vpl;
typedef vector<string> vs;
typedef map<int,int>mi;
typedef map<ll,ll> ml;
typedef set<string> ss;
typedef set<char>sc;
typedef set<int> si;
typedef set<ll> sl;
#define pan cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
// define values.
#define mod 1e9+7LL
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
#define loop(i,start,end) for(ll i=ll(start);i<ll(end);i++)
#define loop0(num) for(ll i=0;i<ll(num);i++)
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

ll power(ll x,   ll y, ll p)  
{  
    ll res = 1;      
    x = x % p;             
    while (y > 0)  
    {    
        if (y & 1)  
            res = (res*x) % p;   
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 
/* ascii value 
A=65,Z=90,a=97,z=122 1=49
*/
/*  -----------------------------------------------------------------------------------*/
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

void show(vector<vector<ll>> v)
{
    for(auto x:v)
    {
        for(auto y:x)
            cout<<y<<" ";
        line;
    }
}

ll determinant(vector<vector<ll>> v)
{
    ll dert=0;
    dert=((v[0][0]*((v[1][1]*v[2][2])-(v[1][2]*v[2][1])))-(v[0][1]*((v[2][2]*v[1][0])-(v[1][2]*v[2][0])))+(v[0][2]*((v[2][1]*v[1][0])-(v[1][1]*v[2][0]))));
    return dert;
}


vector<vector<ll>> transpose(vector<vector<ll>> v)
{
    vector<vector<ll>> trans(3,vector<ll>(3,0));
    for(ll i=0;i<v.size();i++)
    {
        for(ll j=0;j<v[0].size();j++)
        {
            trans[i][j]=v[j][i];
        }
    }
    return trans;
}
int main()
{
    cout<<"Enter all the element of 3x3 matrix : ";
    ll temp=0;
    vector<vector<ll>> v(3,vector<ll>(3,0));
    loop(i,0,3)
    {
        loop(j,0,3)
        {
            cin>>v[i][j];
        }
    }
    cout<<"Press 1: show element of matrix \n2: find determinant \n3: find transpose \n and other for exit : ";
    ll option;
    while(1)
    {
        cin>>option;
        if(option==1)
            show(v);
        else if(option==2)
            cout<<determinant(v)<<endl;
        else if(option==3)
        {
            vector<vector<ll>> temp_v(3,vector<ll>(3,0));
            temp_v=transpose(v);
            show(temp_v);
        }
        else
            break;
    }
    
}