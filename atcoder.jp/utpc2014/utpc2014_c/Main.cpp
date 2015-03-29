#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int n;
int dig[100100];
const int SIZE = 100100;
vector<int> g[100100];
struct UnionFind
{
	int par[SIZE],rank[SIZE];
	void init(int n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x)
	{
		if(par[x] == x)
		{
			return x;
		}
		else
		{
			return par[x] = find(par[x]);
		}
	}
	void unite(int x,int y)
	{
		x = find(x);
		y = find(y);
		if(rank[x] < rank[y])
		{
			par[x] = y;
		}
		else
		{
			par[y] = x;
			if(rank[x] == rank[y])rank[x]++;
		}	
	}
	bool same(int x,int y)
	{
		return find(x) == find(y);
	}
}uf;
int depth[100100];
void dfs(int v,int p,int d)
{
	depth[v]=d;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]==p)continue;
		dfs(g[v][i],v,d+1);
	}
}
int u,v;
int main()
{
	cin >> n;
	uf.init(n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		dig[a]++;
		dig[b]++;
		if(uf.same(a,b))
		{
			u=a;v=b;
		}
		else
		{
			uf.unite(a,b);
			g[a].pb(b);
			g[b].pb(a);
		}
	}
	int mdig=INF;
	for(int i=0;i<n;i++)mdig = min(mdig,dig[i]);
	dfs(0,-1,0);
	if((depth[u]%2)==(depth[v]%2))printf("%d %d\n",mdig,n-1);
	else printf("%d %d\n",mdig,n);
	return 0;
}
