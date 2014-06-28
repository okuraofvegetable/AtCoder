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
#include <iomanip>
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
#define eps 1e-6
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int N,M;
struct UnionFind
{
	int rank[10010],par[10010];
	void init()
	{
		for(int i=0;i<10010;i++)
		{
			rank[i]=0;
			par[i]=i;
		}
	}
	int find(int x)
	{
		if(par[x]==x)return x;
		else return par[x]=find(par[x]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a==b)return;
		if(rank[a]<rank[b])par[a]=b;
		else
		{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
		return;
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
};
struct edge
{
	int a,b,c,t;
	double p;
	edge(int a,int b,int c,int t):a(a),b(b),c(c),t(t){}
	bool operator < (const edge &a) const
	{
		return p > a.p;
	}
};
UnionFind uf;
vector<edge> vec;
bool C(double x)
{
	uf.init();
	for(int i=0;i<vec.size();i++)vec[i].p=(double)x*vec[i].t-(double)vec[i].c;
	SORT(vec);
	double res=0.0;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i].p<=0&&uf.same(vec[i].a,vec[i].b))continue;
		//cout << vec[i].a << ' ' << vec[i].b << ' '; 
		res+=vec[i].p;
		uf.unite(vec[i].a,vec[i].b);
	}
	//cout << x << ' ' << res << endl;
	if(res>=0)return true;
	else return false;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c,t;
		cin >> a >> b >> c >> t;
		edge n(a,b,c,t);
		vec.pb(n);
	}
	double l=0,r=100000000;
	for(int i=0;i<50;i++)
	{
		double mid=(l+r)/2.0;
		if(C(mid))r=mid;
		else l=mid;
	}
	printf("%.12f\n",r);
	return 0;
}