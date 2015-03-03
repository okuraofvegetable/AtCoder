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
#define INF 2000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M;
vector<int> g[5010];
ll s[5010],t[5050];
ll base,ans;
ll dp[5010][5010];
ll mi[5010];
ll tmp[5010];
void rec(int v)
{
	dp[v][0]=0ll;
	dp[v][1]=s[v];
	rep(i,g[v].size())
	{
		int u = g[v][i];
		rec(u);
		rep(k,N+1)tmp[k]=INF;
		for(int j=1;j<=N;j++)
		{
			if(dp[v][j]==INF)break;
			for(int k=0;k<=N;k++)
			{
				if(dp[u][k]==INF)break;
				if(j+k>N)break;
				tmp[j+k]=min(tmp[j+k],dp[v][j]+dp[u][k]);
			}
		}
		rep(k,N+1)dp[v][k]=min(dp[v][k],tmp[k]);
	}
}
int main()
{
	scanf("%d",&N);
	rep(i,N)scanf("%lld",&s[i]);
	rep(i,N-1)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		g[a].pb(b);
	}
	scanf("%d",&M);
	rep(i,M)scanf("%lld",&t[i]);
	sort(t,t+M,greater<int>());
	rep(i,N)base += s[i];
	ans = base;
	rep(i,5010)rep(j,5010)dp[i][j]=INF;
	rec(0);
	ll sum = 0ll;
	rep(i,min(N,M)+1)
	{
		ans = max(ans,base-dp[0][i]+sum);
		sum+=t[i];
	}
	printf("%lld\n",ans);
	return 0;
}
