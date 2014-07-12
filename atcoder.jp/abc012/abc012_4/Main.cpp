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
#define INF 1000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
//int cost[305][305];
int dp[305][305];
int n,m;
int main()
{
	cin >> n >> m;
	for(int i=0;i<305;i++)
	{
		for(int j=0;j<305;j++)
		{
			if(i==j)dp[i][j]=0;
			else dp[i][j]=INF;
		}
	}
	for(int i=0;i<m;i++)
	{
		int a,b,t;
		cin >> a >> b >> t;
		a--;b--;
		dp[a][b]=t;
		dp[b][a]=t;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	int id,ans=INF;
	for(int i=0;i<n;i++)
	{
		int mx=-INF;
		for(int j=0;j<n;j++)
		{
			mx=max(mx,dp[i][j]);
		}
		if(mx<ans)
		{
			id=i;
			ans=mx;
		}
	}
	printf("%d\n",ans);
	return 0;
}
