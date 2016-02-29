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
int N,W,C;
vector<P> obj[55];
int dp[2][55][10005];
int main(){
	scanf("%d %d %d",&N,&W,&C);
	for(int i=0;i<N;i++){
		int w,v,c;
		scanf("%d %d %d",&w,&v,&c);
		c--;
		obj[c].pb(P(w,v));
	}
	memset(dp,0,sizeof(dp));
	for(int c=0;c<50;c++){
		for(int i=0;i<=C;i++){
			for(int j=0;j<=W;j++){
				dp[1][i][j]=-INF;
			}
		}
		int M = sz(obj[c]);
		for(int i=0;i<M;i++){
			int w=obj[c][i].fi,v=obj[c][i].sec;
			for(int j=C;j>=0;j--){
				for(int k=W;k>=0;k--){
					if(j>0&&k-w>=0)dp[1][j][k]=max(dp[1][j][k],dp[0][j-1][k-w]+v);
					if(k-w>=0)dp[1][j][k]=max(dp[1][j][k],dp[1][j][k-w]+v);
				}
			}
		}
		if(M==0)continue;
		//printf("%d:\n",c);
		for(int j=0;j<=C;j++){
			for(int k=0;k<=W;k++){
				dp[0][j][k]=max(dp[0][j][k],dp[1][j][k]);
				//printf("%d ",dp[0][j][k]);
			}
			//printf("\n");
		}
	}
	int ans = 0;
	for(int i=0;i<=C;i++){
		for(int j=0;j<=W;j++){
			ans = max(ans,dp[0][i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}