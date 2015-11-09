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
#define INF 1000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,Q;
struct edge{
	int to;
	ll cost;
	edge(int to,ll cost):to(to),cost(cost){}
};
vector<edge> g[100100];
ll dist[100100];
bool isleaf[100100];
int begin[100100],end[100100];
int id = 0;
vector<int> et;
void dfs(int v,int p,ll c){
	dist[v]=c;
	begin[v]=id++;
	et.pb(v); 
	int cnt = 0;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(e.to==p)continue;
		cnt++;
		dfs(e.to,v,c+e.cost);
	}
	if(cnt==0)isleaf[v]=true;
	end[v]=id;
}
const int SIZE = 1<<17;
struct segtree{
	ll seg[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k){
		seg[k]=seg[k]+lazy[k];
		if(k<SIZE-1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0ll;
	}
	void update(int a,int b,int k,int l,int r,ll x){
		lazy_evaluate(k);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b){
			lazy[k]+=x;
			lazy_evaluate(k);
		}else{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		lazy_evaluate(k);
		if(r<=a||b<=l)return INF;
		else if(a<=l&&r<=b){
			return seg[k];
		}else{
			ll lch = query(a,b,k*2+1,l,(l+r)/2);
			ll rch = query(a,b,k*2+2,(l+r)/2,r);
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
			return min(lch,rch);
		}
	}
}seg;
int p[100100];
int main(){
	scanf("%d %d",&N,&Q);
	for(int i=1;i<N;i++){
		int w;
		scanf("%d %d",&p[i],&w);
		p[i]--;
		g[i].pb(edge(p[i],w));
		g[p[i]].pb(edge(i,w));
	}
	dfs(0,-1,0ll);
	/*for(int i=0;i<N;i++){
		printf("%d %lld %d\n",i,dist[i],isleaf[i]);
	}
	for(int i=0;i<N;i++){
		printf("%d %d %d\n",i,begin[i],end[i]);
	}*/
	for(int i=0;i<N;i++){
		if(isleaf[et[i]])seg.update(i,i+1,0,0,SIZE,dist[et[i]]);
		else seg.update(i,i+1,0,0,SIZE,INF);
	}
	for(int i=0;i<Q;i++){
		int x;
		scanf("%d",&x);
		x--;
		seg.update(begin[x],end[x],0,0,SIZE,INF);
		ll ans = seg.query(0,N,0,0,SIZE);
		if(ans<INF)printf("%lld\n",seg.query(0,N,0,0,SIZE));
		else printf("-1\n");
	}
	return 0;
}