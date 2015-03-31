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
int N;
string S;
int C[5050];
int pal[5010][5010];
int dp[5010];
vector<int> g[5010];
int rec(int l,int r)
{
	if(l>=r)return 1;
	if(pal[l][r]!=-1)return pal[l][r];
	if(S[l]==S[r])return pal[l][r]=rec(l+1,r-1);
	else return pal[l][r]=0;
}
int main()
{
	memset(pal,-1,sizeof(pal));
	scanf("%d",&N);
	cin >> S;
	for(int i=0;i<N;i++)scanf("%d",&C[i]);
	for(int i=0;i<N;i++)dp[i]=INF;
	dp[0]=C[0];
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
	{
		if(rec(i,j))
		{
			if(i==0)dp[j]=C[j-i];
			else g[i-1].pb(j);
		}
	}
	for(int i=0;i<N;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+C[0]);
		for(int j=0;j<g[i].size();j++)
		{
			dp[g[i][j]]=min(dp[g[i][j]],dp[i]+C[g[i][j]-i-1]);
		}
	}
	printf("%d\n",dp[N-1]);
	return 0;
}
