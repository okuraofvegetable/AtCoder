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
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
ll T,U[3010],V[3010],D[3010],E[3010];
ll go[3010],back[3010],turnL[3010],turnR[3010];
ll dp[3010][3010];
ll dp2[3010],dp3[3010];
int main(){
	scanf("%d %lld",&N,&T);
	for(int i=0;i<N;i++){
		scanf("%lld %lld %lld %lld",&U[i],&V[i],&D[i],&E[i]);
		go[i]=U[i]+V[i];
		back[i]=D[i]+E[i];
		turnL[i]=U[i]+E[i];
		turnR[i]=D[i]+V[i];
	}
	for(int i=0;i<3010;i++){
		for(int j=0;j<3010;j++){
			dp[i][j]=LLINF;
		}
	}
	dp[0][0]=T;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=N;j++)dp2[j]=LLINF,dp3[j]=LLINF;
		for(int j=1;j<=N;j++)dp2[j]=min(dp[i-1][j-1]+turnR[i-1]+(j*2+1)*T,dp2[j-1]+turnR[i-1]+2*T);
		for(int j=N-1;j>=0;j--)dp3[j]=min(dp[i-1][j+1]+turnL[i-1]+(j*2+1)*T,dp3[j+1]+turnL[i-1]-2*T);
		for(int j=0;j<=N;j++)dp[i][j]=min(dp2[j],dp3[j]);
		for(int j=0;j<=N;j++){
			dp[i][j]=min(dp[i][j],dp[i-1][j]+go[i-1]+(j*2+1)*T);
			if(j>0)dp[i][j]=min(dp[i][j],dp[i-1][j]+back[i-1]+(j*2+1)*T);
		}
	}
	printf("%lld\n",dp[N][0]);
	return 0;
}