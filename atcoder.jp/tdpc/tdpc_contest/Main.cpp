#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int dp[105][10010];
int N,p[105];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&p[i]);
	dp[0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<=10000;j++){
			if(j-p[i]>=0)dp[i+1][j]|=dp[i][j-p[i]];
			dp[i+1][j]|=dp[i][j];
		}
	}
	int ans = 0;
	for(int i=0;i<=10000;i++)if(dp[N][i])ans++;
	printf("%d\n",ans);
	return 0;
}