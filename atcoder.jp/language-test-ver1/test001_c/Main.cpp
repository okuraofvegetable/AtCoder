#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
typedef pair<string,string> String;
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
	int c[10];
	int n;
	for(int i=0;i<10;i++)
	{
		int k;
		cin >> k;
		c[k]=i;
	}
	vector<String> vec[10];
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		string t=s;
		for(int j=0;j<t.size();j++)
		{
			t[j]=(c[t[j]-'0']+'0');
		}
		vec[t.size()].pb(String(t,s));
	}
	for(int i=0;i<10;i++)
	{
		SORT(vec[i]);
	}
	for(int j=0;j<10;j++)
	{
		for(int i=0;i<vec[j].size();i++)
		{
			cout << vec[j][i].sec << endl;
		}
	}
	return 0;
}
