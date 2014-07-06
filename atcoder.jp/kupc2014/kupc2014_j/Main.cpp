#include <iostream>
using namespace std;
#define INF 200000000
int N,M,P;
int x[22];
int dp[110][110];
int main()
{
	cin >> N >> M >> P;
	for(int i=1;i<=M;i++)cin >> x[i];
	for(int i=1;i<=M;i++)x[i]+=x[i-1];
	for(int i=0;i<110;i++)
	{
		for(int j=0;j<110;j++)
		{
			dp[i][j]=-INF;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		{
			for(int k=0;k<=min(j,M);k++)
			{
				if(dp[i-1][j-k]+P-x[k]>=0)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-k]+P-x[k]);
				}
			}
			if(j==N&&dp[i][j]>=0)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}
