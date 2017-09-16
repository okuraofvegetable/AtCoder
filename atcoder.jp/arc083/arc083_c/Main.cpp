#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-15
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
ll dp[1010];
int N;
vector<int> g[1010];
int X[1010];
int dp2[1010][5010];
int rec(int v){
	ll sum = 0;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(rec(u)==-1)return -1;
		sum += (ll)(X[u]+dp[u]);
	}
	for(int i=0;i<=g[v].size();i++){
		for(int j=0;j<=5000;j++){
			dp2[i][j]=0;
		}
	}
	dp2[0][0]=1;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		for(int j=0;j<=5000;j++){
			if(j>=X[u]&&dp2[i][j-X[u]]==1)dp2[i+1][j]=1;
			if(j>=dp[u]&&dp2[i][j-dp[u]]==1)dp2[i+1][j]=1;
		}
	}
	int ret = -1;
	for(int i=0;i<=X[v];i++)if(dp2[(int)g[v].size()][i]==1)ret=i;
	if(ret==-1){
		return -1;
	}
	return dp[v]=sum-ret;
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int par;
		scanf("%d",&par);
		par--;
		g[par].pb(i); 
	}
	for(int i=0;i<N;i++)scanf("%d",&X[i]);
	//for(int i=N-1;i>=0;i--)cout << rec(i) << endl;
	if(rec(0)==-1)printf("IMPOSSIBLE\n");
	else printf("POSSIBLE\n");
	return 0;
}