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
int sum[10000];
int a[10000];
int par[10000];
vector<int> g[10000];
void dfs(int v,int s)
{
	s+=a[v];
	sum[v]=s;
	for(int i=0;i<g[v].size();i++)
	{
		dfs(g[v][i],s);
	}
	return;
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		int s;
		cin >> s >> a[i];
		if(s==0)continue;
		s--;
		g[s].pb(i);
		par[i]=s;
	}
	int ans=0;
	for(int i=0;i<m;i++)
	{
		memset(sum,0,sizeof(sum));
		dfs(0,0);
		int v=-1,s=-1;
		for(int j=0;j<n;j++)
		{
			if(sum[j]>s)
			{
				s=sum[j];
				v=j;
			}
		}
		ans+=s;
		while(1)
		{
			a[v]=0;
			if(v==par[v])break;
			v=par[v];
		}
		/*for(int i=0;i<n;i++)
		{
			cout << a[i] << endl;
		}*/
	}
	cout << ans << endl;
	return 0;
}
