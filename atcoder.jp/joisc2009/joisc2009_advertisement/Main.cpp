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
vector<int> G[100005];
vector<int> rG[100005];
vector<int> vs;
bool used[100005];
P cmp[100005];
void add_edge(int from,int to)
{
	G[from].pb(to);
	rG[to].pb(from);
}
void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.pb(v);
	return;
}
void rdfs(int v,int x)
{
	used[v]=true;
	cmp[v]=mp(x,v);
	for(int i=0;i<rG[v].size();i++)
	{
		if(!used[rG[v][i]])rdfs(rG[v][i],x);
	}
	return;
}
void scc()
{
	memset(used,false,sizeof(used));
	for(int i=0;i<n;i++)
	{
		if(!used[i])dfs(i);
	}
	memset(used,false,sizeof(used));
	int p=0;
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]])
		{
			rdfs(vs[i],p);
			p++;
		}
	}
	return;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		add_edge(a,b);
	}
	scc();
	/*for(int i=0;i<vs.size();i++)
	{
		cout << vs[i] << ' ';
	}
	cout << endl;
	for(int i=0;i<n;i++)
	{
		cout << cmp[i].fi << endl;
	}*/
	sort(cmp,cmp+n);
	int ans=0;
	memset(used,false,sizeof(used));
	for(int i=0;i<n;i++)
	{
		if(!used[cmp[i].sec])
		{
			dfs(cmp[i].sec);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
