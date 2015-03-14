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
int N,M,K;
struct edge
{
	int from,to,cost;
	edge(int from,int to,int cost):from(from),to(to),cost(cost){}
	bool operator < (const edge& a) const
	{
		return cost < a.cost;
	}
};
struct UnionFind
{
	int par[100100],rank[100100];
	void init(){rep(i,100100)par[i]=i;}
	int find(int x)
	{
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void unite(int a,int b)
	{
		a = find(a);
		b = find(b);
		if(a==b)return;
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
}uf;
vector<edge> es;
int main()
{
	scanf("%d %d %d",&N,&M,&K);
	rep(i,M)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		es.pb(edge(a,b,c));
	}
	sort(all(es));
	uf.init();
	int cnt = 0,ans = 0;
	rep(i,es.size())
	{
		if(cnt==N-K)break;
		if(uf.same(es[i].from,es[i].to))continue;
		uf.unite(es[i].from,es[i].to);
		cnt++;
		ans += es[i].cost;
	}
	printf("%d\n",ans);
	return 0;
}
