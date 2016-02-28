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
#define MOD 1000000007
int N,K;
ll dp[1000100],rui[1000100],ruirui[1000100];
int main(){
	scanf("%d %d",&N,&K);
	dp[1]=1;rui[1]=1;ruirui[1]=1;
	for(int i=2;i<=N;i++){
		ll r = (i-K-1>0)?ruirui[i-K-1]:0;
		dp[i]=(ruirui[i-2]-r+MOD)%MOD;
		if(i<K)dp[i]=(dp[i]+1)%MOD;
		rui[i]=(rui[i-1]+dp[i])%MOD;
		ruirui[i]=(ruirui[i-1]+rui[i])%MOD;
		//printf("%lld %lld %lld\n",dp[i],rui[i],ruirui[i]);
	}
	printf("%lld\n",dp[N]);
	return 0;
}