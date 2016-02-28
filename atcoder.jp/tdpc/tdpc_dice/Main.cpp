#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> P;
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
ll D;
int cnt[7];
double dp[105][60][40][30];
int main(){
	scanf("%d %lld",&N,&D);
	while(D%2ll==0){
		cnt[2]++;
		D/=2ll;
	}
	while(D%3ll==0){
		cnt[3]++;
		D/=3ll;
	}
	while(D%5ll==0){
		cnt[5]++;
		D/=5ll;
	}
	if(D!=1ll){
		printf("0.0\n");
		return 0;
	}
	dp[0][0][0][0]=1.0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=cnt[2];j++){
			for(int k=0;k<=cnt[3];k++){
				for(int l=0;l<=cnt[5];l++){
					dp[i+1][j][k][l]+=dp[i][j][k][l]/6.0;
					dp[i+1][min(j+1,cnt[2])][k][l]+=dp[i][j][k][l]/6.0;
					dp[i+1][j][min(k+1,cnt[3])][l]+=dp[i][j][k][l]/6.0;
					dp[i+1][min(j+2,cnt[2])][k][l]+=dp[i][j][k][l]/6.0;
					dp[i+1][j][k][min(l+1,cnt[5])]+=dp[i][j][k][l]/6.0;
					dp[i+1][min(j+1,cnt[2])][min(k+1,cnt[3])][l]+=dp[i][j][k][l]/6.0;
				}
			}
		}
	}
	printf("%.12f\n",dp[N][cnt[2]][cnt[3]][cnt[5]]);
	return 0;
}