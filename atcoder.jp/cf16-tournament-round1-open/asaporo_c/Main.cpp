#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
struct UnionFind{
	int par[4010],rank[4010];
	void init(){
		for(int i=0;i<4010;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		if(par[x]==x)return x;
		else return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y)return;
		if(rank[x]>rank[y])par[y]=x;
		else{
			par[x]=y;
			rank[y]++;
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
}uf;
struct edge{
	int from,to;
	ll cost;
	edge(){}
	edge(int from,int to,ll cost):from(from),to(to),cost(cost){}
	bool operator < (const edge &a) const{
		return cost < a.cost;
	}
};
int N,M,Q;
vector<edge> es;
vector<edge> g[4010];
int par[15][4010];
ll cost[15][4010];
int depth[4010];
void add_edge(edge e){
	g[e.from].pb(e);
	swap(e.from,e.to);
	g[e.from].pb(e);
}
void dfs(int v,int p,int c,int d){
	depth[v]=d;
	par[0][v]=p;
	cost[0][v]=c;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(e.to==p)continue;
		dfs(e.to,v,e.cost,d+1);
	}
}
ll query(int u,int v){
	//cout << u << ' ' << v << endl;
	if(depth[u]>depth[v])swap(u,v);
	ll res = 0ll;
	for(int i=14;i>=0;i--){
		if(((depth[v]-depth[u])>>i)&1){
			res = max(res,cost[i][v]);
			v = par[i][v];
		}
	}
	if(u==v)return res;
	for(int i=14;i>=0;i--){
		if(par[i][u]!=par[i][v]){
			res = max(res,cost[i][u]);
			res = max(res,cost[i][v]);
			u = par[i][u];
			v = par[i][v];
		}
	}
	res = max(res,cost[0][u]);
	res = max(res,cost[0][v]);
	assert(par[0][u]==par[0][v]);
	return res;
}
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		ll c;
		cin >> a >> b >> c;
		a--;b--;
		es.pb(edge(a,b,c));
	}
	sort(all(es));
	uf.init();
	ll base = 0ll;
	for(int i=0;i<es.size();i++){
		if(uf.same(es[i].from,es[i].to))continue;
		base += es[i].cost;
		uf.unite(es[i].from,es[i].to);
		//cout << es[i].from << ' ' << es[i].to << ' ' << es[i].cost << endl;
		add_edge(es[i]);
	}
	dfs(0,-1,-1,0);
	/*for(int i=0;i<N;i++){
		printf("%d %d %lld\n",i,par[0][i],cost[0][i]);
	}*/
	for(int i=0;i<14;i++){
		for(int j=0;j<N;j++){
			if(par[i][j]==-1){
				par[i+1][j]=-1;
				cost[i+1][j]=cost[i][j];
			}else{
				par[i+1][j]=par[i][par[i][j]];
				cost[i+1][j]=max(cost[i][j],cost[i][par[i][j]]);
			}
		}
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		int S,T;
		cin >> S >> T;
		S--;T--;
		cout << base-query(S,T) << endl;
	}
	return 0;
}