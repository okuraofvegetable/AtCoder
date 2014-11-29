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
#define EQ(a,b) (abs((a)-(b))<eps)
int N,x;
int h[105];
int child[105];
vector<int> g[105];
void cnt(int v,int p)
{
	if(h[v]==1)child[v]+=1;
	for(int i=0;i<g[v].size();i++)
	{
		int e = g[v][i];
		if(e==p)continue;
		cnt(e,v);
		child[v]+=child[e];
	}
	return;
}
int rec(int v,int p)
{
	if(child[v]==0)return -1;
	int res=0;
	for(int i=0;i<g[v].size();i++)
	{
		int e = g[v][i];
		if(e==p)continue;
		res ++;
		res += rec(e,v);
	}
	return res;
}
int main()
{
	memset(child,0,sizeof(child));
	cin >> N >> x;
	x--;
	for(int i=0;i<N;i++)cin >> h[i];
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	cnt(x,-1);
	//for(int i=0;i<N;i++)cout << child[i] << endl;
	cout << max(rec(x,-1),0)*2 << endl;
	return 0;
}
