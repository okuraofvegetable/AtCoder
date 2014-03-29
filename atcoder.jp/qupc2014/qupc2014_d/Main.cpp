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
int d[30010];
int p[30010];
int N,M,K,S,G;
struct edge{int to,cost;};
vector<edge> g[300010];
vector<int> c;
vector<int> f;
void dijkstra(int s)
{
	fill(d,d+N,INF);
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(mp(0,s));
	while(!q.empty())
	{
		P a=q.top();
		q.pop();
		int v=a.sec;
		if(a.fi>d[v])continue;
		for(int i=0;i<g[v].size();i++)
		{
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				q.push(mp(d[e.to],e.to));
			}
		}
	}
	return;
}
void copy()
{
	for(int i=0;i<N;i++)p[i]=d[i];
	return;
}
int main()
{
	cin >> N >> M >> K;
	cin >> S >> G;
	for(int i=0;i<M;i++)
	{
		int  a,b,dist;
		cin >> a >> b >> dist;
		edge nx;
		nx.to=b;nx.cost=dist;
		g[a].pb(nx);
		nx.to=a;
		g[b].pb(nx);
	}
	for(int i=0;i<K;i++)
	{
		int x,fl;
		cin >> x >> fl;
		c.pb(x);
		f.pb(fl);
	}
	c.pb(INF);
	f.pb(INF);
	int ans=INF;
	dijkstra(S);
	copy();
	dijkstra(G);
	for(int i=0;i<N;i++)
	{
		if(d[i]==INF||p[i]==INF)continue;
		int res=0;
		int k=upper_bound(c.begin(),c.end(),p[i])-c.begin();
		k--;
		res+=f[k];
		k=upper_bound(c.begin(),c.end(),d[i])-c.begin();
		k--;
		res+=f[k];
		ans=min(ans,res);
	}
	cout << ans << endl;
	return 0;
}
