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
#define MOD 1000000007 // prime
const int SIZE = 100100;
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
int N;
vector<int> g[1010];
int chnum[1010];
ll dp[1010];
void dfs(int v,int p){
	chnum[v]=0;
	dp[v]=1;
	for(int i=0;i<g[v].size();i++){
		int to = g[v][i];
		if(to==p)continue;
		dfs(to,v);
		dp[v]=(dp[v]*facinv[chnum[to]])%MOD;
		dp[v]=(dp[v]*dp[to])%MOD;
		chnum[v]+=chnum[to];
	}
	dp[v]=(dp[v]*fac[chnum[v]])%MOD;
	chnum[v]++;
}
int main(){
	init();
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		dfs(i,-1);
		ans = (ans+dp[i])%MOD;
	}
	ans = (ans*inv[2])%MOD;
	printf("%lld\n",ans);
	return 0;
}