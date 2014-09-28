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
#define EQ(a,b) (abs((a)-(b))<eps)
struct UnionFind
{
	int par[100100],rank[100100];
	void init()
	{
		for(int i=0;i<100100;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(x==par[x])return x;
		else return par[x]=find(par[x]);
	}
	void unite(int a,int b)
	{
		a = find(a);
		b = find(b);
		if(rank[a]<rank[b])par[a]=b;
		else
		{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
};
struct edge
{
	int from,to;
	ll cost;
	edge(int from,int to,ll cost):from(from),to(to),cost(cost){}
	bool operator < (const edge& a) const
	{
		return cost < a.cost;
	}
};
UnionFind uf;
vector<edge> edges;
ll ans=0;
int n,m;
int main()
{
	uf.init();
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		ll c;
		cin >> c;
		edges.pb(edge(0,i+1,c));
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		ll c;
		cin >> a >> b >> c;
		edges.pb(edge(a,b,c));
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();i++)
	{
		edge a = edges[i];
		if(!uf.same(a.from,a.to))
		{
			ans+=a.cost;
			uf.unite(a.from,a.to);
		}
	}
	cout << ans << endl;
	return 0;
}
