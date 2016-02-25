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
#define INF 100000000000.0
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
struct edge{
	int to;
	double d,t;
	edge(){}
	edge(int _to,int _d,int _f){
		to = _to;
		d = (double)_d;
		t = (double)_d/(double)_f;
	}
};
int n,m,c;
vector<edge> g[10010];
int direct[10010];
bool used[10010];
double dp[10010];
vector<int> vs;
void dfs(int v){
	used[v]=true;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(!used[e.to])dfs(e.to);
	}
	vs.pb(v);
}
bool check(double x){
	for(int i=1;i<n;i++)dp[i]=INF;
	dp[n]=0.0;
	for(int i=0;i<n;i++){
		int v = vs[i];
		if(dp[v]==INF)continue;
		for(int j=0;j<g[v].size();j++){
			edge e = g[v][j];
			dp[e.to]=min(dp[e.to],dp[v]+(e.d-e.t*x));
		}
	}
	for(int i=0;i<m;i++)if(dp[direct[i]]<=0.0)return true;
	return false;
}
int main(){
	scanf("%d %d %d",&n,&m,&c);
	for(int i=0;i<m;i++)scanf("%d",&direct[i]);
	for(int i=0;i<c;i++){
		int u,v,d,f;
		scanf("%d %d %d %d",&u,&v,&d,&f);
		g[v].pb(edge(u,d,f));
	}
	memset(used,false,sizeof(used));
	for(int i=1;i<=n;i++)if(!used[i])dfs(i);
	reverse(all(vs));
	double l = 0.0,r = 1000000.0;
	for(int i=0;i<100;i++){
		double mid = (l+r)/2.0;
		if(check(mid))r = mid;
		else l = mid;
	}
	printf("%d\n",(int)(r+0.5));
	return 0;
}