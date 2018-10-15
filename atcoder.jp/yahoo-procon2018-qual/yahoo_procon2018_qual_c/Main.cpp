#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 20000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
ll x[20],c[20],v[20];
ll dp[1<<18][20];
ll dp2[1<<18];
ll rec1(int S,int k){
	if(dp[S][k]!=-1ll)return dp[S][k];
	ll sumC = 0ll;
	ll sumV = 0ll;
	for(int i=0;i<N;i++){
		if((S>>i)&1){
			sumC += c[i];
			sumV += v[i];
		}
	}
	if(x[k]>=sumC)return dp[S][k]=sumV;
	dp[S][k]=0ll;
	for(int i=0;i<N;i++){
		if((S>>i)&1){
			dp[S][k]=max(dp[S][k],rec1(S^(1<<i),k));
		}
	}
	return dp[S][k];
}
ll rec2(int S){
	if(dp2[S]!=-1ll)return dp2[S];
	int cnt = 0;
	ll res = LLINF;
	for(int i=0;i<N;i++){
		if((S>>i)&1){
			cnt++;
			res = min(res,rec2(S^(1<<i)));
		}
	}
	if(res==LLINF)res=0ll;
	return dp2[S]=max(rec1(S,N-cnt),res);
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld",&x[i]);
		x[i]+=x[i-1];
	}
	for(int i=0;i<N;i++){
		scanf("%lld",&c[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%lld",&v[i]);
	}
	for(int i=0;i<(1<<N);i++){
		dp2[i]=-1ll;
		for(int j=0;j<N;j++){
			dp[i][j]=-1ll;
		}
	}
	cout << rec2((1<<N)-1) << endl;
	return 0;
}