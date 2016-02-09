#include <bits/stdc++.h>
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
int N,R,C;
int ax=INF,ay=INF,bx=-1,by=-1;
ll fac[4010];
ll dp[3010][3010];
ll mpow(ll a,ll x){
	ll res = 1ll;
	while(x){
		if(x&1)res = (res*a)%MOD;
		a = (a*a)%MOD;
		x >>= 1;
	}
	return res;
}
ll fact(int x){
	if(x<4000)return fac[x];
	ll res = 1;
	for(int i=1;i<=x;i++)res = (res*(ll)i)%MOD;
	return res;
}
ll func(int a,int b){
	ll res = fact(a+b);
	ll inva = mpow(fact(a),MOD-2);
	ll invb = mpow(fact(b),MOD-2);
	res = (res*inva%MOD)*invb%MOD;
	return res;
}
int main(){
	scanf("%d %d",&R,&C);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		ax = min(ax,x);
		ay = min(ay,y);
		bx = max(bx,x);
		by = max(by,y);
	}
	fac[0]=1ll;
	for(int i=1;i<4000;i++)fac[i]=(fac[i-1]*(ll)i)%MOD;
	int cx = bx-ax+1,cy = by-ay+1;
	int f = cx*cy-N;
	int rx = R-cx,ry = C-cy;
	dp[0][0]=1ll;
	for(int i=0;i<=rx;i++){
		for(int j=0;j<=ry;j++){
			if(i<rx)dp[i+1][j] = (dp[i+1][j]+dp[i][j]*fac[cy+j])%MOD;
			if(j<ry)dp[i][j+1] = (dp[i][j+1]+dp[i][j]*fac[cx+i])%MOD;
		}
	}
	ll ans = fact(f)*dp[rx][ry]%MOD;
	ans = ans*func(ax-1,R-bx)%MOD;
	ans = ans*func(ay-1,C-by)%MOD;
	printf("%lld\n",ans);
	return 0;
}