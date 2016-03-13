#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
#define MOD 1000000007ll
const int SIZE = 1000100;
ll inv[SIZE+10],fac[SIZE+10],facinv[SIZE+10];
ll nCr(int n,int r){
	if(n<r)return -1ll;
	if(n<0||r<0)return -1ll;
	if(n==0&&r==0)return 1ll;
	return ((fac[n]*facinv[r]%MOD)*facinv[n-r])%MOD;
}
void init(){
	fac[0]=1ll;
	for(int i=1;i<=SIZE;i++)fac[i]=(fac[i-1]*i)%MOD;
	inv[1]=1ll;
	for(int i=2;i<=SIZE;i++)inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
	facinv[0]=1ll;
	for(int i=1;i<=SIZE;i++)facinv[i]=(facinv[i-1]*inv[i])%MOD;
}
ll mod_pow(ll a,ll x,ll mod){
	ll res = 1ll;
	while(x){
		if(x&1)res = (res*a)%mod;
		a = (a*a)%mod;
		x >>= 1;
	}
	return res;
}
int N,K;
ll ans = 0ll;
int main(){
	init();
	scanf("%d %d",&N,&K);
	int M = N-K;
	for(int i=0;i<=M;i++){
		ll f = (mod_pow(2,mod_pow(2ll,M-i,MOD-1),MOD)+MOD-1)%MOD;
		ll c = nCr(M,i);
		ll add = (f*c)%MOD;
		if(i%2==0)ans = (ans+add)%MOD;
		else ans = (ans+MOD-add)%MOD;
	}
	ans = ans*nCr(N,K)%MOD;
	printf("%lld\n",ans);
	return 0;
}