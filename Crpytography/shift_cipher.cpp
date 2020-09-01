#include<iostream>
using namespace std;
typedef long long ll;
/* ascii value 
A=65,Z=90,a=97,z=122 1=49
*/

string shift_encrpyt(string s,ll k)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>=97&&s[i]<=122)
		{
			int temp=int(s[i]);
			temp+=k;
			if(temp>122)
				temp-=97;
			s[i]=char(temp);
		}
		else if(s[i]>=65&&s[i]<=90)
		{
			int temp=int(s[i]);
			temp+=k;
			if(temp>90)
				temp-=65;
			s[i]=char(temp);
		}
	}
	return s;
}

void shift_decription(string s,ll k)
{
	string temp_s=s;
	for(int k=1;k<=26;k++)
	{
		for(int i=0;i<s.length();i++)
		{
			if(temp_s[i]>=97&&temp_s[i]<=122)
			{
				int temp=int(s[i]);
				temp-=k;
				if(temp<97)
					temp+=26;
				temp_s[i]=char(temp);
			}
			else if(temp_s[i]>=65&&temp_s[i]<=90)
			{
				int temp=int(temp_s[i]);
				temp-=k;
				if(temp<65)
					temp+=26;
				temp_s[i]=char(temp);
			}
		}
		cout<<"decrypt string is "<<temp_s<<"  for key is  "<<k<<endl;
	}
}

int main()
{
	cout<<"Enter string : ";
	string s;
	int k;
	getline(cin,s);
	cout<<"Enter key (shift position) : ";
	cin>>k;
	k=k%26;
	s=shift_encrpyt(s,k);
	cout<<"Encrpyted string is "<<s<<endl;
	shift_decription(s,k);
}