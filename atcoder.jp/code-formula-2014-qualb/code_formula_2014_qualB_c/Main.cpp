#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
int a[30],b[30];
vector<string> sh(string a)
{
	vector<string> v;
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			string p=a;
			swap(p[i],p[j]);
			v.pb(p);
		}
	}
	return v;
}
int main()
{
	string s,t;
	cin >> s;
	cin >> t;
	int diff=0;
	bool otori=false;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=t[i])diff++;
		a[s[i]-'a']++;
		b[t[i]-'a']++;
	}
	if(diff>=7)
	{
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;i<30;i++)
	{
		if(a[i]>1)otori=true;
		if(a[i]!=b[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	string x,y;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=t[i])
		{
			x+=s[i];
			y+=t[i];
		}
	}
	string kara;
	if(x==kara)
	{
		if(otori)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		return 0;
	}
	vector<string> vec[5];
	vec[0].pb(x);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			vector<string> ap=(sh(vec[i][j]));
			for(int k=0;k<ap.size();k++)
			{
				vec[i+1].pb(ap[k]);
			}
		}
	}
	for(int i=0;i<vec[3].size();i++)
	{
		if(y==vec[3][i])
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	if(otori)
	{
		for(int i=0;i<vec[2].size();i++)
		{
			if(y==vec[2][i])
			{
				cout << "YES" <<endl;
				return 0;
			}
		}
		for(int i=0;i<vec[1].size();i++)
		{
			if(vec[1][i]==y)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
		if(x==y)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
