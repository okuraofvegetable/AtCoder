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
const int MAX_V = 100100;
const int V = 10000;
struct Bipartite_matching
{
	vector<int> G[MAX_V];
	int match[MAX_V];
	bool used[MAX_V];
	void add_edge(int u,int v)
	{
		G[u].pb(v);
		G[v].pb(u);
	}
	bool dfs(int v)
	{
		used[v]=true;
		for(int i=0;i<G[v].size();i++)
		{
			int u=G[v][i],w=match[u];
			if(w<0||!used[w]&&dfs(w))
			{
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int bipartite_matching()
	{
		int res=0;
		memset(match,-1,sizeof(match));
		for(int v=0;v<V;v++)
		{
			if(match[v]<0)
			{
				memset(used,0,sizeof(used));
				if(dfs(v))res++;
			}
		}
		return res;
	}
}bm;
int M,N;
int A[100][100];
int B[100][100];
vector<P> l,r;
int ans = 0;
bool adj(P a,P b)
{
	return (abs(a.fi-b.fi)+abs(a.sec-b.sec)==1);
}
int main()
{
	scanf("%d %d",&M,&N);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(A[i][j]==B[i][j])continue;
			ans++;
			if(A[i][j]==0)l.pb(P(i,j));
			else r.pb(P(i,j));
		}
	}
	//cout << ans << endl;
	int ls = l.size();
	for(int i=0;i<l.size();i++)
	{
		for(int j=0;j<r.size();j++)
		{
			if(adj(l[i],r[j]))
			{
				bm.add_edge(i,ls+j);
				//cout << i << ' ' << ls+j << endl;
			}
		}
	}
	printf("%d\n",ans-bm.bipartite_matching());	
	return 0;
}
