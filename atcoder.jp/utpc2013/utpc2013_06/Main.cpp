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
const int SIZE=2005;
int n,m,q;
int ex[SIZE][SIZE];
struct edge{int from,to,cost;};
vector<edge> e[SIZE];
bool comp(edge a,edge b)
{
	return a.cost<b.cost;
}
struct UnionFind
{
	bool use_option;
	int par[SIZE],rank[SIZE];
	vector<int> v[SIZE];
	UnionFind(bool in)
	{
		use_option=in;
		memset(rank,0,sizeof(rank));
		for(int i=0;i<SIZE;i++)par[i]=i;
		if(use_option)for(int i=0;i<SIZE;i++)v[i].pb(i);
	}
	int find(int x)
	{
		if(par[x]==x)return x;
		return find(par[x]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(rank[a]<rank[b])
		{
			par[a]=b;
			if(use_option)
			{
				for(int i=0;i<v[a].size();i++)v[b].pb(v[a][i]);
				v[a].clear();
			}
		}
		else
		{
			par[b]=a;
			if(use_option)
			{
				for(int i=0;i<v[b].size();i++)v[a].pb(v[b][i]);
				v[b].clear();
			}
			if(rank[a]==rank[b])rank[a]++;
		}
		return;
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
};
UnionFind uf(true);
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		ex[a][b]=c;
		ex[b][a]=c;
	}
	cin >> q;
	while(q--)
	{
		int s,t;
		cin >> s >> t;
		s=uf.find(s);
		t=uf.find(t);
		vector<edge> vec;
		for(int i=0;i<e[s].size();i++)vec.pb(e[s][i]);
		e[s].clear();
		for(int i=0;i<e[t].size();i++)vec.pb(e[t][i]);
		e[t].clear();
		for(int i=0;i<uf.v[s].size();i++)
		{
			for(int j=0;j<uf.v[t].size();j++)
			{
				int nx=uf.v[s][i],ny=uf.v[t][j];
				//cout << nx <<' '<< ny << endl;
				//if(nx>=SIZE||ny>=SIZE)return 0;
				if(ex[nx][ny])
				{
					edge e;
					e.from=nx,e.to=ny,e.cost=ex[nx][ny];
					vec.pb(e);
				}
			}
		}
		UnionFind uf2(false);
		sort(vec.begin(),vec.end(),comp);
		int mc=0,cnt=0;
		vector<edge> use;
		for(int i=0;i<vec.size();i++)
		{
			if(!uf2.same(vec[i].from,vec[i].to))
			{
				mc+=vec[i].cost;
				cnt++;
				use.pb(vec[i]);
				uf2.unite(vec[i].from,vec[i].to);
			}
		}
		if(cnt+1==uf.v[s].size()+uf.v[t].size())
		{
			cout << mc << endl;
		}
		else
		{
			cout << "IMPOSSIBLE" << endl;
		}
		uf.unite(s,t);
		s=uf.find(s);
		e[s]=use;
	}
	return 0;
}
