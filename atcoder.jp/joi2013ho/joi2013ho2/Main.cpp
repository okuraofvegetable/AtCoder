#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
string s,t;
int dp[2050][2050][2];
int ans=-1;
int main()
{
	scanf("%d %d",&n,&m);
	cin >> s;
	cin >> t;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i<n&&s[i]=='I')dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]+1);
			else if(i<n)dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][1]+1);
			if(j<m&&t[j]=='I')dp[i][j+1][1]=max(dp[i][j+1][1],dp[i][j][0]+1);
			else if(j<m)dp[i][j+1][0]=max(dp[i][j+1][0],dp[i][j][1]+1);
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			ans=max(ans,dp[i][j][1]);
		}
	}
	if(ans==0)
	{
		printf("0\n");
	}
	else printf("%d\n",ans-((ans+1)%2));
	return 0;
}
