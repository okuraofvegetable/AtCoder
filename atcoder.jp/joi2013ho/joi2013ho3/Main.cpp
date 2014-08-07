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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,int> P2;
typedef pair<pair<ll,ll>,int> T;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 20000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
int M,N,K;
struct edge
{
	int to;
	ll cost;
	edge(int to,ll cost):to(to),cost(cost){}
};
vector<edge> G[400100];
ll x[200100],y[200100];
ll d[400100];
int s=-1,t=-1,room;
vector<T> xy,yx;
void add_edge(int from,int to,ll cost)
{
	G[from].pb(edge(to,cost));
	G[to].pb(edge(from,cost));
	return;
}
void dijkstra(int S)
{
	for(int i=0;i<400100;i++)d[i]=INF;
	d[S]=0;
	priority_queue<P2,vector<P2>,greater<P2> > q;
	q.push(P2(0ll,S));
	while(!q.empty())
	{
		P2 a=q.top();
		q.pop();
		int v=a.sec;
		if(d[v]<a.fi)continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				q.push(P2(d[e.to],e.to));
			}
		}
	}
	return;
}
int main()
{
	scanf("%d %d %d",&M,&N,&K);
	room=K;
	for(int i=0;i<K;i++)
	{
		scanf("%lld %lld",&x[i],&y[i]);
		if(x[i]==1&&y[i]==1)s=i;
		if(x[i]==M&&y[i]==N)t=i;
	}
	if(s==-1)
	{
		s=room;
		x[room]=1;y[room]=1;
		room++;
	}
	if(t==-1)
	{
		t=room;
		x[room]=M;y[room]=N;
		room++;
	}
	for(int i=0;i<K;i++)add_edge(i,i+room,1ll);
	for(int i=0;i<room;i++)
	{
		xy.pb(T(P(x[i],y[i]),i));
		yx.pb(T(P(y[i],x[i]),i));
	}
	SORT(xy);
	SORT(yx);
	for(int i=1;i<room;i++)
	{
		if(xy[i-1].fi.fi==xy[i].fi.fi)add_edge(xy[i-1].sec,xy[i].sec,xy[i].fi.sec-xy[i-1].fi.sec);
		if(yx[i-1].fi.fi==yx[i].fi.fi)add_edge(yx[i-1].sec+room,yx[i].sec+room,yx[i].fi.sec-yx[i-1].fi.sec);
	}
	dijkstra(s);
	if(d[t]==INF&&d[t+room]==INF)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",min(d[t],d[t+room]));
	return 0;
}
