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
int n,m;
int x0,a,p;
int f[1005][1005];
ll ans=0ll;
vector<int> vec[1005];
int main()
{
	cin >> n >> m;
	cin >> x0 >> a >> p;
	if(a%p==0)
	{
		if(x0<p)cout << 0 << endl;
		else cout << 2*n-2 << endl;
		return 0;
	}
	f[0][0]=x0;
	vector<int> v;
	v.pb(f[0][0]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0&&j==0)continue;
			if(j>0)f[i][j]=(f[i][j-1]+a)%p;
			else f[i][j]=(f[i-1][m-1]+a)%p;
			v.pb(f[i][j]);
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int k=(lower_bound(v.begin(),v.end(),f[i][j])-v.begin())/m;
			vec[k].pb(j);
			ans+=abs(k-i);
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(vec[i].begin(),vec[i].end());
		for(int j=0;j<m;j++)
		{
			ans+=abs(vec[i][j]-j);
		}
	}
	cout << ans << endl;
	return 0;
}
