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
int N,M;
struct edge
{
	int to,cost;
	edge(int to,int cost):to(to),cost(cost){}
};
vector<edge> g[30100];
int X,divide;
int dfs(int v,int p)
{
	vector<int> vec;
	for(int i=0;i<g[v].size();i++)
	{
		edge e = g[v][i];
		if(e.to==p)continue;
		int f = dfs(e.to,v)+e.cost;
		if(f<=X)vec.pb(f);
		else divide++;
	}
	if(vec.empty())return 0;
	sort(all(vec),greater<int>());
	int i;
	for(i=0;i<(int)vec.size()-1;i++)
	{
		if(vec[i]+vec[i+1]>X)divide++;
		else break;
	}
	if(i==(int)vec.size()-1)return vec[(int)vec.size()-1];
	return vec[i];
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		g[a].pb(edge(b,c));
		g[b].pb(edge(a,c));
	}
	int l=-1,r=INF;
	while(r-l>1)
	{
		int mid = (l+r)/2;
		X = mid;
		divide = 0;
		dfs(0,-1);
		if(divide>=M)l=mid;
		else r = mid;
	}
	printf("%d\n",r);
	return 0;
}
