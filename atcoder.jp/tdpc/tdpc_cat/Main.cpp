#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
int f[1010][1010];
int cost[1010][1010];
int dp[1010][1010];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&f[i][j]);
		}
	}
	for(int i=1;i<=N;i++){
		cost[i][i]=0;
		for(int j=i+1;j<=N;j++){
			cost[i][j]=cost[i][j-1]+f[i][j];
		}
	}
	for(int i=0;i<=N;i++)dp[0][i]=-INF;
	dp[0][0]=0;
	for(int i=1;i<=N;i++){
		int pre = dp[i-1][i-1];
		for(int j=i;j<=N;j++){
			pre = max(pre,dp[i-1][j]);
			dp[i][j]=pre+cost[i][j]*2;
		}
	}
	printf("%d\n",dp[N][N]);
	return 0;
}