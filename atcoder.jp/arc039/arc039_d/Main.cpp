#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert> 
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MAX_V 100100
#define MAX_E 200100
struct edge{
	int to,id;
	edge(int to,int id):to(to),id(id){}
};
vector<edge> g[MAX_V];
bool used_v[MAX_V],used_e[MAX_E];
int ord[MAX_V],lowlink[MAX_V],depth[MAX_V];
int k=0;
void dfs(int v,int d){
	used_v[v]=true;
	ord[v]=lowlink[v]=k++;
	depth[v]=d;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(!used_v[e.to]){
			used_e[e.id]=true;
			dfs(e.to,d+1);
			lowlink[v]=min(lowlink[v],lowlink[e.to]);
		}
		else if(!used_e[e.id])
		//then,e(v,g[v][i]) is backward edge
		{
			lowlink[v]=min(lowlink[v],ord[e.to]);
		}
	}
	return;
}
// e(u,v) is bridge <=> ord(u) < lowlink(v) (u is parent of v)
// vが関節点 <=> ord[u] ≦ lowlink[v]となるvの子が存在する(if v != root)
//           <=> 子が2つ以上 (if v is root)
bool is_bri[200100];
bool used[MAX_V];
int cmp[MAX_V];
int tree_id[MAX_V];
int mxid=0;
void dfs2(int v,int tid,int id){
	used[v]=true;
	cmp[v]=id;
	tree_id[v]=tid;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(!used[e.to]){
			if(is_bri[e.id])dfs2(e.to,tid,++mxid);
			else dfs2(e.to,tid,id);
		}
	}
}
#define MAX_LOG_V 20
vector<int> G[MAX_V];
bool Used[MAX_V];
int Depth[MAX_V];
int Par[MAX_V][MAX_LOG_V];
void Dfs(int v,int p,int d){
	Used[v]=true;
	Depth[v]=d;
	Par[v][0]=p;
	for(int i=0;i<G[v].size();i++){
		if(!Used[G[v][i]])Dfs(G[v][i],v,d+1);
	}
}
void init(){
	for(int i=0;i<MAX_LOG_V-1;i++){
		for(int j=0;j<mxid;j++){
			if(Par[j][i]==-1)Par[j][i+1]=-1;
			else Par[j][i+1]=Par[Par[j][i]][i];
		}
	}
}
int lca(int u,int v){
	if(Depth[u]<Depth[v])swap(u,v);
	for(int i=MAX_LOG_V-1;i>=0;i--){
		if((Depth[u]-Depth[v])&(1<<i)){
			u = Par[u][i];
		}
	}
	if(u==v)return u;
	for(int i=MAX_LOG_V-1;i>=0;i--){
		if(Par[u][i]!=Par[v][i]){
			u=Par[u][i];
			v=Par[v][i];
		}
	}
	return Par[u][0];
}
int Dist(int u,int v){
	int lc = lca(u,v);
	return Depth[u]+Depth[v]-Depth[lc]*2;
}
int N,M,Q;
int X[200100],Y[200100];
void debug(){
	for(int i=0;i<N;i++)printf("cmp %d %d\n",i,cmp[i]);
	for(int i=0;i<N;i++)printf("tid %d %d\n",i,tree_id[i]);
	for(int i=0;i<M;i++)printf("%d %d\n",i,(int)is_bri[i]);
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d",&X[i],&Y[i]);
		X[i]--;Y[i]--;
		g[X[i]].pb(edge(Y[i],i));
		g[Y[i]].pb(edge(X[i],i));
	}
	memset(used_v,false,sizeof(used_v));
	memset(used_e,false,sizeof(used_e));
	for(int i=0;i<N;i++){
		if(!used_v[i])dfs(i,0);
	}
	for(int i=0;i<M;i++){
		if(depth[X[i]]>depth[Y[i]])swap(X[i],Y[i]);
		if(ord[X[i]]<lowlink[Y[i]])is_bri[i]=true;
	}
	memset(used,false,sizeof(used));
	k=0;
	int cnt=0;
	for(int i=0;i<N;i++){
		if(!used[i]){
			dfs2(i,cnt++,mxid);
			mxid++;
		}
	}
	for(int i=0;i<M;i++){
		if(is_bri[i]){
			G[cmp[X[i]]].pb(cmp[Y[i]]);
			G[cmp[Y[i]]].pb(cmp[X[i]]);
		}
	}
	//debug();
	memset(Used,false,sizeof(Used));
	memset(Par,-1,sizeof(Par));
	for(int i=0;i<mxid;i++){
		if(!Used[i])Dfs(i,-1,0);
	}
	init();
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;c--;
		if(!(tree_id[a]==tree_id[b]&&tree_id[b]==tree_id[c])){
			printf("NG\n");
		}else{
			//printf("%d %d %d %d\n",cmp[a],cmp[c],lca(cmp[a],cmp[c]),cmp[b]);
			if(Dist(cmp[a],cmp[b])+Dist(cmp[b],cmp[c])==Dist(cmp[a],cmp[c]))printf("OK\n");
			else printf("NG\n");
		}
	}
	
	return 0;
}