#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T &a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T &a,const T& b){if(a<b)a=b;}
struct edge{
	int to,cost;
	edge(){}
	edge(int to,int cost):to(to),cost(cost){}
};
int N,M;
int S[1010];
vector<edge> g[1010];
bool used[1010];
vector<int> topo;
int cmp[1010];
int d[1010][1010];
int dp[1010][1010];
vector<int> cp;
void dfs(int v){
	used[v]=true;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(!used[e.to])dfs(e.to);
	}
	topo.pb(v);
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&S[i]);
	S[0]=1;S[N-1]=1;
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;-b--;
		g[a].pb(edge(b,c));
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++){
		if(!used[i])dfs(i);
	}
	reverse(all(topo));
	for(int i=0;i<topo.size();i++)cmp[topo[i]]=i;
	//for(int i=0;i<topo.size();i++)printf("%d ",topo[i]);
	//printf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			d[i][j]=INF;
			dp[i][j]=INF;
			if(i==j)d[i][j]=0;	
		}
	}
	for(int i=0;i<N;i++){
		int v = topo[i];
		if(S[v]==1){
			cp.pb(v);
			for(int j=cmp[v];j<N;j++){
				for(int k=0;k<g[topo[j]].size();k++){
					edge e = g[topo[j]][k];
					d[v][e.to]=min(d[v][e.to],d[v][topo[j]]+e.cost);
				}
			}
		}
	}
	int K = cp.size();
	/*for(int i=0;i<K;i++)printf("%d ",cp[i]);
	printf("\n");
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			printf("%d ",d[cp[i]][cp[j]]);
		}
		printf("\n");
	}*/
	dp[0][0]=0;
	for(int i=0;i<K;i++){
		for(int j=i;j<K;j++){
			if(j==i){
				if(j+1<K)chmin(dp[i][j+1],dp[i][j]+d[cp[j]][cp[j+1]]);
			}else{
				if(j+1<K)chmin(dp[j][j+1],dp[i][j]+d[cp[i]][cp[j+1]]);
				if(j+1<K)chmin(dp[i][j+1],dp[i][j]+d[cp[j]][cp[j+1]]);
				chmin(dp[j][j],dp[i][j]+d[cp[i]][cp[j]]);
			}
		}
	}
	printf("%d\n",dp[K-1][K-1]);
	return 0;
}