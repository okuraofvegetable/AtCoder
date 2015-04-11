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
#define MOD 1000000007
int N,M;
int a,b;
vector<int> g[105];
int used[105];
ll ans[105];
int d[105];
void bfs(int s)
{
	memset(ans,-1,sizeof(ans));
	memset(d,-1,sizeof(d));
	ans[s]=1ll;
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int i=0;i<g[v].size();i++)
		{
			if(d[g[v][i]]<0)
			{
				d[g[v][i]]=d[v]+1;
				ans[g[v][i]]=ans[v];
				q.push(g[v][i]);
			}
			else if(d[g[v][i]]==d[v]+1)
			{
				ans[g[v][i]]+=ans[v];
				ans[g[v][i]]%=MOD;
			}
		}
	}
	return;
}
int main()
{
	cin >> N;
	cin >> a >> b;
	a--;b--;
	cin >> M;
	for(int i=0;i<M;i++)
	{
		int x,y;
		cin >> x >> y;
		x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	bfs(a);
	cout << ans[b] << endl;
	return 0;
}
