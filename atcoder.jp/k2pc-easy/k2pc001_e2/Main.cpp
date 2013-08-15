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
char c[101][8];
int main()
{
	int n;
	vector<int> a,b;
	cin >> n;
	for(int i=0;i<10;i++)
	{
		int k;
		cin >> k;
		a.pb(k);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<7;j++)
		{
			cin >> c[i][j];
		}
	}
	for(int j=0;j<7;j++)
	{
		int res=0;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(c[i][j]=='X')count++;
			else
			{
				res=max(res,count);
				count=0;
			}
		}
                res=max(res,count);
		b.pb(res);
	}
	sort(a.begin(),a.end());
	bool flag=true;
	for(int i=0;i<7;i++)
	{
		vector<int>::iterator it;
		it=lower_bound(a.begin(),a.end(),b[i]);
		if(it==a.end())
		{
			flag=false;
			break;
		}
		else a.erase(it);
	}
	if(flag)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
