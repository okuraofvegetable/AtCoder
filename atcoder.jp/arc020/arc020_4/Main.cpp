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
#define MOD 1000000007
int N,M,K;
int D[105];
ll dp[105][1<<10][30];
int main(){
	scanf("%d %d %d",&N,&M,&K);
	for(int i=1;i<N;i++){
		scanf("%d",&D[i]);
	}
	dp[0][0][0]=1ll;
	for(int i=1;i<=N;i++){
		for(int mask=0;mask<(1<<K);mask++){
			int cnt = 0;
			for(int j=1;j<K;j++){
				if(((mask>>j)&1)!=((mask>>(j-1))&1))cnt++;
			}
			for(int j=0;j<M;j++){
				int pj = ((j-D[i]*cnt)%M+M)%M;
				dp[i][mask][j]+=dp[i-1][mask][pj];
				dp[i][mask][j]%=MOD;
				for(int k=0;k<K;k++){
					if((mask>>k)&1){
						dp[i][mask][j]+=dp[i-1][mask-(1<<k)][pj];
						dp[i][mask][j]%=MOD;
					}
				}
			}
		}
	}
	printf("%lld\n",dp[N][(1<<K)-1][0]);
	return 0;
}