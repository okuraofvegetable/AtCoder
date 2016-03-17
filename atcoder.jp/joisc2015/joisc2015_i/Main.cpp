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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
int C[505],A[505],V[505];
int dp[505][505][505];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d %d %d",&C[i],&A[i],&V[i]);
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N+3;j++){
			for(int k=0;k<=N+3;k++){
				dp[i][j][k]=-INF;
			}
		}
	}
	int ans = 0;
	dp[0][1][2]=0;
	for(int j=0;j<=N+3;j++){
		for(int k=0;k<=N+3;k++){
			for(int i=0;i<=N;i++){
				if(dp[i][j][k]==-INF)continue;
				int l = max(i,k)+1;
				if(i==0){
					if(j<=N)chmax(dp[j][k][l],dp[i][j][k]+V[j]);
					if(l<=N)chmax(dp[l][j][k],dp[i][j][k]+V[l]);
				}else{
					if(j<=N&&(C[i]==C[j]||A[i]==A[j]))chmax(dp[j][k][l],dp[i][j][k]+V[j]);
					if(l<=N&&(C[i]==C[l]||A[i]==A[l]))chmax(dp[l][j][k],dp[i][j][k]+V[l]);
				}
			}
		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N+3;j++){
			for(int k=0;k<=N+3;k++){
				ans = max(ans,dp[i][j][k]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}