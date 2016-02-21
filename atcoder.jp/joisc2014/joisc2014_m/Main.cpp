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
P st[2010];
int dp[2010][2010];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&st[i].fi,&st[i].sec);
	}
	sort(st,st+N);
	reverse(st,st+N);
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			dp[i][j]=-INF;
		}
	}
	dp[0][1]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=N;j++){
			if(dp[i][j]==-INF)continue;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+st[i].fi-1<0)continue;
			dp[i+1][min(j+st[i].fi-1,N)]=max(dp[i+1][min(j+st[i].fi-1,N)],dp[i][j]+st[i].sec);
		}
	}
	int ans = 0;
	for(int i=0;i<=N;i++)ans=max(ans,dp[N][i]);
	printf("%d\n",ans);
	return 0;
}