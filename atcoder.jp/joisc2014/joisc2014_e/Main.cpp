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
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 200100;
struct UnionFind{
	int par[SIZE],rank[SIZE];
	void init(){
		for(int i=0;i<SIZE;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void unite(int a,int b){
		a = find(a);
		b = find(b);
		if(a==b)return;
		if(rank[a]<rank[b])par[a]=b;
		else{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
}uf;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};;
int H,W,p,Q;
string f[2010];
int px[200100],py[200100];
P dist[2010][2010];
vector<T> es;
vector<P> g[200100];
int depth[200100];
int par[200100][20];
int maxcost[200100][20];
inline bool valid(int x,int y){
	if(x<0||x>=H||y<0||y>=W)return false;
	return true;
}
void dfs(int v,int parent,int c,int d){
	par[v][0]=parent;
	maxcost[v][0]=c;
	depth[v]=d;
	for(int i=0;i<g[v].size();i++){
		int to = g[v][i].fi;
		int cost = g[v][i].sec;
		if(to==parent)continue;
		dfs(to,v,cost,d+1);
	}
}
void bfs(){
	queue<int> q;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			dist[i][j]=P(INF,-1);
		}
	}
	for(int i=0;i<p;i++){
		dist[px[i]][py[i]]=P(0,i);
		q.push(px[i]);
		q.push(py[i]);
	}
	while(!q.empty()){
		int x = q.front();q.pop();
		int y = q.front();q.pop();
		int d = dist[x][y].fi;
		int id = dist[x][y].sec;
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(!valid(nx,ny))continue;
			if(f[nx][ny]=='#')continue;
			if(dist[nx][ny].fi<INF)continue;
			dist[nx][ny]=P(d+1,id);
			q.push(nx);
			q.push(ny);
		}
	}
}
void make(){
	for(int i=0;i<19;i++){
		for(int j=0;j<p;j++){
			if(par[j][i]==-1){
				par[j][i+1]=-1;
				maxcost[j][i+1]=INF;
			}else{
				par[j][i+1]=par[par[j][i]][i];
				maxcost[j][i+1]=max(maxcost[j][i],maxcost[par[j][i]][i]);
			}
		}
	}
}
int lca(int u,int v){
	int ret = -1;
	if(depth[u]>depth[v])swap(u,v);
	for(int i=19;i>=0;i--){
		if((depth[v]-depth[u])&(1<<i)){
			ret = max(ret,maxcost[v][i]);
			v = par[v][i];
		}
	}
	if(u==v)return ret;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			ret = max(ret,maxcost[u][i]);
			ret = max(ret,maxcost[v][i]);
			u = par[u][i];
			v = par[v][i];
		}
	}
	ret = max(ret,maxcost[u][0]);
	ret = max(ret,maxcost[v][0]);
	return ret;
}
int main(){
	scanf("%d %d %d %d",&H,&W,&p,&Q);
	for(int i=0;i<H;i++){
		cin >> f[i];
	}
	for(int i=0;i<p;i++){
		scanf("%d %d",&px[i],&py[i]);
		px[i]--;py[i]--;
	}
	bfs();
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(f[i][j]=='#')continue;
			P dij = dist[i][j];
			for(int k=0;k<4;k++){
				int ni=i+dx[k],nj=j+dy[k];
				if(!valid(ni,nj))continue;
				P ndij = dist[ni][nj];
				if(dij.sec!=ndij.sec&&dij.sec!=-1&&ndij.sec!=-1){
					es.pb(T(dij.fi+ndij.fi,P(dij.sec,ndij.sec)));
				}
			}
		}
	}
	sort(all(es));
	uf.init();
	for(int i=0;i<es.size();i++){
		int cost = es[i].fi;
		int a = es[i].sec.fi , b = es[i].sec.sec;
		if(!uf.same(a,b)){
			uf.unite(a,b);
			g[a].pb(P(b,cost));
			g[b].pb(P(a,cost));
		}
	}
	for(int i=1;i<p;i++){
		if(!uf.same(0,i)){
			uf.unite(0,i);
			g[0].pb(P(i,INF));
			g[i].pb(P(0,INF));
		}
	}
	dfs(0,-1,INF,0);
	make();
	for(int i=0;i<Q;i++){
		int s,t;
		scanf("%d %d",&s,&t);
		s--;t--;
		int ans = lca(s,t);
		if(ans==INF)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}