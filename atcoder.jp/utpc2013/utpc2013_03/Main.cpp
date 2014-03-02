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
int n1,m1,n2,m2;
vector<int> g1[1005],g2[1005];
int ml1[1005],ml2[1005];
bool used[1005];
void add_edge1(int a,int b)
{
	g1[a].pb(b);g1[b].pb(a);
	return;
}
void add_edge2(int a,int b)
{
	g2[a].pb(b);g2[b].pb(a);
	return;
}
void bfs1(int v)
{
	memset(used,0,sizeof(used));
	queue<P> q;
	q.push(mp(v,0));
	used[v]=true;
	while(!q.empty())
	{
		P a=q.front();
		q.pop();
		for(int i=0;i<g1[a.fi].size();i++)
		{
			if(used[g1[a.fi][i]])continue;
			used[g1[a.fi][i]]=true;
			ml1[v]=max(ml1[v],a.sec+1);
			q.push(mp(g1[a.fi][i],a.sec+1));
		}
	}
	return;
}
void bfs2(int v)
{
	memset(used,0,sizeof(used));
	queue<P> q;
	q.push(mp(v,0));
	used[v]=true;
	while(!q.empty())
	{
		P a=q.front();
		q.pop();
		for(int i=0;i<g2[a.fi].size();i++)
		{
			if(used[g2[a.fi][i]])continue;
			used[g2[a.fi][i]]=true;
			ml2[v]=max(ml2[v],a.sec+1);
			q.push(mp(g2[a.fi][i],a.sec+1));
		}
	}
	return;
}
int main()
{
	cin >> n1 >> m1;
	for(int i=0;i<m1;i++)
	{
		int a,b;
		cin >> a >> b;
		add_edge1(a,b);
	}
	cin >> n2 >> m2;
	for(int i=0;i<m2;i++)
	{
		int a,b;
		cin >> a >> b;
		add_edge2(a,b);
	}
	int max1=0,max2=0,min1=INF,min2=INF;
	for(int i=0;i<n1;i++)
	{
		bfs1(i);
		max1=max(max1,ml1[i]);
		min1=min(min1,ml1[i]);
	}
	for(int i=0;i<n2;i++)
	{
		bfs2(i);
		max2=max(max2,ml2[i]);
		min2=min(min2,ml2[i]);
	}
	cout << max(max(max1,max2),min1+min2+1) << ' ' << max1+max2+1 << endl;
	return 0;
}
