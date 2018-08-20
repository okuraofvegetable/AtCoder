#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
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
const int SIZE = 100100;
struct UnionFind{
	int par[SIZE],rank[SIZE];
	void init(int n){
		for(int i=0;i<n;i++){
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y)return;
		if(rank[x] < rank[y])par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y])rank[x]++;
		}	
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
}uf;
struct edge{
	int from,to,cost;
	edge(){}
	edge(int f,int t,int c):from(f),to(t),cost(c){}
	bool operator < (const edge a) const{
		return cost < a.cost;
	}
};
int cost(T a, T b){
	return min(abs(a.fi.fi-b.fi.fi),abs(a.fi.sec-b.fi.sec));
}
int N;
T x[100100];
vector<edge> es;
int main(){
	scanf("%d",&N);
	uf.init(N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&x[i].fi.fi,&x[i].fi.sec);
		x[i].sec = i;
	}
	sort(x,x+N);
	for(int i=0;i<N-1;i++){
		es.pb(edge(x[i].sec,x[i+1].sec,cost(x[i],x[i+1])));
	}
	for(int i=0;i<N;i++){
		swap(x[i].fi.fi,x[i].fi.sec);
	}
	sort(x,x+N);
	for(int i=0;i<N-1;i++){
		es.pb(edge(x[i].sec,x[i+1].sec,cost(x[i],x[i+1])));
	}
	sort(es.begin(),es.end());
	ll ans = 0ll;
	for(int i=0;i<es.size();i++){
		int a = es[i].from;
		int b = es[i].to;
		int c = es[i].cost;
		if(uf.same(a,b))continue;
		uf.unite(a,b);
		ans += (ll)c;
	}
	cout << ans << endl;
	return 0;
}