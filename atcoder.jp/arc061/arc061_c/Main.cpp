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
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M;
int p[200100],q[200100],c[200100];
vector<P> g[200100];
vector<int> cs[200100];
int sz[200100];
vector<P> G[600100];
int dist[600100];
int id;
int new_node(){
	return id++;
}
void add_edge(int i,int ci,int j,int cj,int cost){
	int a,b;
	if(ci!=-1)a = sz[i]+ci;
	else a = i;
	if(cj!=-1)b = sz[j]+cj;
	else b = j;
	//printf("%d -> %d : %d\n",a,b,cost);
	G[a].pb(P(b,cost));
}
void dijkstra(int s){
	for(int i=0;i<id;i++)dist[i]=INF;
	priority_queue<P,vector<P>,greater<P> > q;
	dist[s]=0;
	q.push(P(0,s));
	while(!q.empty()){
		P a = q.top();
		q.pop();
		int v = a.sec;
		if(dist[v]<a.fi)continue;
		for(int i=0;i<G[v].size();i++){
			int u = G[v][i].fi;
			int c = G[v][i].sec;
			if(dist[u]>a.fi+c){
				dist[u]=a.fi+c;
				q.push(P(dist[u],u));
			}
		}
	}
	return;
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&p[i],&q[i],&c[i]);
		p[i]--;q[i]--;c[i]--;
		g[p[i]].pb(P(q[i],c[i]));
		g[q[i]].pb(P(p[i],c[i]));
		cs[p[i]].pb(c[i]);
		cs[q[i]].pb(c[i]);
	}
	cs[0].pb(INF);
	for(int i=0;i<N;i++){
		sort(all(cs[i]));
		cs[i].erase(unique(all(cs[i])),cs[i].end());
		sz[i+1]=cs[i].size();
	}
	for(int i=1;i<=N;i++)sz[i]+=sz[i-1];
	id = sz[N];
	for(int i=0;i<N;i++){
		int tmp = new_node();
		for(int j=0;j<cs[i].size();j++){
			if(cs[i][j]==INF)continue;
			add_edge(i,j,tmp,-1,1);
		}
		for(int j=0;j<g[i].size();j++){
			int v = g[i][j].fi;
			int c = g[i][j].sec;
			int idx = lower_bound(all(cs[i]),c)-cs[i].begin();
			int vdx = lower_bound(all(cs[v]),c)-cs[v].begin();
			if(idx<cs[i].size())add_edge(i,idx,v,vdx,0);
			add_edge(tmp,-1,v,vdx,0);
		}
	}
	for(int i=0;i<g[0].size();i++){
		int v = g[0][i].fi;
		int c = g[0][i].sec;
		int vdx = lower_bound(all(cs[v]),c)-cs[v].begin();
		add_edge(0,sz[1]-1,v,vdx,1);
	}
	dijkstra(sz[1]-1);
	int ans = INF;
	for(int i=0;i<cs[N-1].size();i++){
		ans = min(ans,dist[sz[N-1]+i]);
	}
	if(ans==INF)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}