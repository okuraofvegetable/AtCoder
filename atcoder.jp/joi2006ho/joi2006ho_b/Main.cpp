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
#define EQ(a,b) (abs((a)-(b))<EPS)
string s;
vi all;
vector<char> num;
string itos(int a)
{
	ostringstream s;
	s<<a;
	return s.str();
}
void conv()
{
	all.clear();
	num.clear();
	string tmp;
	int t=0;
	for(int i=0;i<s.size();i++)
	{
		if(s.size()==1)
		{
			num.pb(s[0]);
			all.pb(1);
			break;
		}
		if(i==0)
		{
			t++;
			continue;
		}
		if(i==s.size()-1)
		{
			if(s[i-1]==s[i])
			{
				++t;
				num.pb(s[i-1]);
				all.pb(t);
			}
			else
			{
				num.pb(s[i-1]);
				all.pb(t);
				num.pb(s[i]);
				all.pb(1);
			}
			break;
		}
		if(s[i-1]==s[i])
		{
			t++;
		}
		else
		{
			num.pb(s[i-1]);
			all.pb(t);
			t=1;
		}
	}
	for(int i=0;i<all.size();i++)
	{
		tmp+=itos(all[i]);
		tmp+=num[i];
	}
	s.clear();
	s=tmp;
	return ;
}
int main()
{
	int n;
	//while(1)
	{
		s.clear();
		cin >> n;
		// if(n==0)break;
		cin >> s;
		for(int i=0;i<n;i++)
		{
			conv();
		}
		cout << s << endl;
	}
	return 0;
}
