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
struct edge{
	int from,to;
	ll cost;
	edge(){}
	edge(int from,int to,ll cost):from(from),to(to),cost(cost){}
	bool operator < (const edge& a) const{
		return cost < a.cost;
	}
};
struct event{
	int x,type;
	P l,r; // [l,r]
	event(){}
	event(int x,P l,P r,int type):x(x),l(l),r(r),type(type){}
	bool operator < (const event& a) const{
		if(x!=a.x)return x < a.x;
		return type < a.type;
	}
};
const int SIZE = 1<<20;
struct segtree{
	int seg[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k,int l,int r){
		seg[k]+=lazy[k]*(r-l);
		if(k<SIZE-1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update(int a,int b,int k,int l,int r,int x){
		lazy_evaluate(k,l,r);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b){
			lazy[k]+=x;
			lazy_evaluate(k,l,r);
		}else{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			seg[k]=seg[k*2+1]+seg[k*2+2];
		}
	}
	int query(int a,int b,int k,int l,int r){
		lazy_evaluate(k,l,r);
		if(r<=a||b<=l)return 0;
		else if(a<=l&&r<=b){
			return seg[k];
		}else{
			int lch = query(a,b,k*2+1,l,(l+r)/2);
			int rch = query(a,b,k*2+2,(l+r)/2,r);
			seg[k]=seg[k*2+1]+seg[k*2+2];
			return lch+rch;
		}
	}
	void update(int a,int b,int x){
		update(a,b,0,0,SIZE,x);
	}
	int query(int a,int b){
		return query(a,b,0,0,SIZE);
	}
};
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
		else return par[x]=find(par[x]);
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
};
int N,M,C;
int X[200100],Y[200100],H[500100];
int p[200100],q[200100],r[200100],s[200100];
ll B[500100];
vector<P> fx[600100],fy[600100];
vector<int> zx,zy;
vector<ll> uc;
vector<edge> es;
vector<event> evx,evy;
segtree seg;
UnionFind uf;
int main(){
	scanf("%d %d %d",&N,&M,&C);
	for(int i=0;i<N;i++){
		scanf("%d %d",&X[i],&Y[i]);
		zx.pb(X[i]);
		zy.pb(Y[i]);
	}
	for(int i=0;i<M;i++){
		scanf("%d %d %d %d",&p[i],&q[i],&r[i],&s[i]);
		zx.pb(p[i]);zx.pb(r[i]);
		zy.pb(q[i]);zy.pb(s[i]);
	}
	for(int i=0;i<C;i++){
		scanf("%lld %d",&B[i],&H[i]);
	}
	sort(all(zx));
	sort(all(zy));
	zx.erase(unique(all(zx)),zx.end());
	zy.erase(unique(all(zy)),zy.end());
	for(int i=0;i<N;i++){
		X[i] = lower_bound(all(zx),X[i])-zx.begin();
		Y[i] = lower_bound(all(zy),Y[i])-zy.begin();
	}
	for(int i=0;i<M;i++){
		p[i] = lower_bound(all(zx),p[i])-zx.begin();
		q[i] = lower_bound(all(zy),q[i])-zy.begin();
		r[i] = lower_bound(all(zx),r[i])-zx.begin();
		s[i] = lower_bound(all(zy),s[i])-zy.begin();
	}
	// | --->
	for(int i=0;i<N;i++){
		fx[X[i]].pb(P(Y[i],i));
	}
	for(int i=0;i<zx.size();i++)sort(all(fx[i]));
	for(int i=0;i<zx.size();i++){
		for(int j=1;j<fx[i].size();j++){
			evx.pb(event(i,fx[i][j-1],fx[i][j],1));
		}
	}
	for(int i=0;i<M;i++){
		evx.pb(event(p[i],P(q[i],-1),P(s[i],-1),0));
		evx.pb(event(r[i],P(q[i],-1),P(s[i],-1),2));
	}
	sort(all(evx));
	for(int i=0;i<evx.size();i++){
		event e = evx[i];
		//printf("%d %d %d %d\n",zx[e.x],zy[e.l.fi],zy[e.r.fi],e.type);
		if(e.type==0){
			seg.update(e.l.fi,e.r.fi+1,1);
		}else if(e.type==1){
			if(seg.query(e.l.fi,e.r.fi+1)==0){
				es.pb(edge(e.l.sec,e.r.sec,zy[e.r.fi]-zy[e.l.fi]));
			}
		}else{
			seg.update(e.l.fi,e.r.fi+1,-1);
		}
	}
	// ----- ^
	for(int i=0;i<N;i++){
		fy[Y[i]].pb(P(X[i],i));
	}
	for(int i=0;i<zy.size();i++)sort(all(fy[i]));
	for(int i=0;i<zy.size();i++){
		for(int j=1;j<fy[i].size();j++){
			evy.pb(event(i,fy[i][j-1],fy[i][j],1));
		}
	}
	for(int i=0;i<M;i++){
		evy.pb(event(q[i],P(p[i],-1),P(r[i],-1),0));
		evy.pb(event(s[i],P(p[i],-1),P(r[i],-1),2));
	}
	sort(all(evy));
	for(int i=0;i<evy.size();i++){
		event e = evy[i];
		//printf("%d %d %d %d\n",zy[e.x],zx[e.l.fi],zx[e.r.fi],e.type);
		if(e.type==0){
			seg.update(e.l.fi,e.r.fi+1,1);
		}else if(e.type==1){
			if(seg.query(e.l.fi,e.r.fi+1)==0){
				es.pb(edge(e.l.sec,e.r.sec,zx[e.r.fi]-zx[e.l.fi]));
			}
		}else{
			seg.update(e.l.fi,e.r.fi+1,-1);
		}
	}
	sort(all(es));
	ll base = 0ll;
	uf.init();
	for(int i=0;i<es.size();i++){
		edge e = es[i];
		//printf("%d %d %lld\n",e.from,e.to,e.cost);
		if(!uf.same(e.from,e.to)){
			uf.unite(e.from,e.to);
			uc.pb(e.cost);
			base += e.cost;
		}
	}
	int cnt = sz(uc);
	vector<ll> sum = uc;
	sum.pb(0ll);
	for(int i=cnt-1;i>=0;i--)sum[i]+=sum[i+1];
	for(int i=0;i<C;i++){
		if(N-cnt>H[i]){
			printf("-1\n");
		}else{
			ll ans = base+(N-cnt)*B[i];
			int k = upper_bound(all(uc),B[i])-uc.begin();
			int chg = min(H[i]-(N-cnt),cnt-k);
			ans += B[i]*(ll)chg-sum[cnt-chg];
			printf("%lld\n",ans);
		}
	}
	return 0;
}