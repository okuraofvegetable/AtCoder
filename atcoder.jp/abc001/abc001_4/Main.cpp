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
#define EQ(a,b) (abs((a)-(b))<EPS)
int main()
{
	int n;
	cin >> n;
	vector<P> vec;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		int a=0,b=0;
		for(int i=3;i>=0;i--)
		{
			a+=(s[i]-'0')*((int)pow(10,3-i));
			b+=(s[i+5]-'0')*((int)pow(10,3-i));
		}
		a-=a%5;
		if(5-b%5!=5)
		{
			b+=5-b%5;
		}
		if(b%100==60)
		{
			b-=60;
			b+=100;
		}
		vec.pb(P(a,b));
	}
	SORT(vec);
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	vector<P> ans;
	ans.pb(vec[0]);
	for(int i=1;i<vec.size();i++)
	{
		if(ans[ans.size()-1].sec>=vec[i].fi)
		{
			ans[ans.size()-1].sec=max(vec[i].sec,ans[ans.size()-1].sec);
		}
		else
		{
			ans.pb(vec[i]);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		int p=ans[i].fi,q=ans[i].sec;
		//cout << p <<' '<<q;
		for(int i=4;i>0;i--)
		{
			cout << (p%((int)pow(10,i))-p%((int)pow(10,i-1)))/((int)pow(10,i-1));
		}
		cout << '-' ;
		for(int i=4;i>0;i--)
		{
			cout << (q%((int)pow(10,i))-q%((int)pow(10,i-1)))/((int)pow(10,i-1));
		}
		cout << endl;
	}
	return 0;
}
