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
#define EQ(a,b) (abs((a)-(b))<eps)
int n;
vector<int> g[100100];
int sub[100100];
int ans[100100];
int dfs(int v,int p)
{
	sub[v]=1;
	int mx=0;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]==p)continue;
		int f=dfs(g[v][i],v);
		sub[v]+=f;
		mx=max(mx,f);
	}
	ans[v]=max(n-sub[v],mx);
	return sub[v];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int x;
		scanf("%d",&x);
		g[x].pb(i+1);
		g[i+1].pb(x);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
