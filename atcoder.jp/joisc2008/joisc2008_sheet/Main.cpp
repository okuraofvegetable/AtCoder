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
int map[101][101];
int n,w,h;
int r[1001],l[1001],u[1001],d[1001];
vector<int> g[1001];
bool used[1001];
vector<int> vs;
void check(int a,int b)
{
	for(int i=max(u[a],u[b]);i<=min(d[a],d[b]);i++)
	{
		for(int j=max(l[a],l[b]);j<=min(r[a],r[b]);j++)
		{
			if(map[i][j]==a)
			{
				g[a].pb(b);
				return;

			}
			else if(map[i][j]==b)
			{
				g[b].pb(a);
				return;
			}
		}
	}
	return;
}
void dfs(int v)
{
	if(!used[v])
	{
		used[v]=true;
		for(int i=0;i<g[v].size();i++)
		{
			dfs(g[v][i]);
		}
		vs.pb(v);
	}
	return;
}
int main()
{
	cin >> n >> w >> h;
	fill(l,l+n+1,INF);
	fill(u,u+n+1,INF);
	memset(r,-1,sizeof(r));
	memset(d,-1,sizeof(d));
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> map[i][j];
			int num=map[i][j];
			r[num]=max(r[num],j);
			l[num]=min(l[num],j);
			u[num]=min(u[num],i);
			d[num]=max(d[num],i);
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		cout << i << ':' << l[i] <<' '<< r[i]<<' '<<u[i]<<' '<<d[i]<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			check(i,j);
		}
	}
	memset(used,0,sizeof(used));
	for(int i=1;i<=n;i++)
	{
		dfs(i);
	}
	/*for(int i=1;i<=n;i++)
	{
		cout << i << ':';
		for(int j=0;j<g[i].size();i++)
		{
			printf("%d",g[i][j]);
		}
		puts("");
	}*/
	for(int i=0;i<vs.size();i++)
	{
		if(i!=vs.size()-1)
		{
			cout << vs[i] << ' ';
		}
		else
		{
			cout << vs[i] << endl;
		}
	}
	return 0;
}

