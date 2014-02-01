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
int n,d;
int price[370][3050];
int dp[2][3050][3];
int m[370];
int main()
{
	cin >> n >> d;
	fill(m,m+370,INF);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<3;k++)
			{
				dp[i][j][k]=INF;
			}
		}
	}
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> price[i][j];
			if(i==0)
			{
				dp[0][j][0]=price[i][j];
				m[0]=min(m[0],dp[0][j][0]);
			}
		}
	}
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[(i+1)%2][j][2]=min(dp[i%2][j][1]+price[i+1][j]/10*7,dp[i%2][j][2]+price[i+1][j]/10*7);
			dp[(i+1)%2][j][1]=dp[i%2][j][0]+price[i+1][j]/10*9;
			dp[(i+1)%2][j][0]=m[i]+price[i+1][j];
			m[i+1]=min(dp[(i+1)%2][j][2],m[i+1]);
			m[i+1]=min(dp[(i+1)%2][j][1],m[i+1]);
			m[i+1]=min(dp[(i+1)%2][j][0],m[i+1]);
		}
	}
	int ans=INF;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans=min(ans,dp[(d-1)%2][i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
