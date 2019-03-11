#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
const int SIZE = 100100;
struct UnionFind{
	int par[SIZE],rank[SIZE],sz[SIZE];
	void init(int n){
		for(int i=0;i<n;i++){
			par[i] = i;
			rank[i] = 0;
			sz[i]=1;
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
		if(rank[x] < rank[y]){
			par[x] = y;
			sz[y]+=sz[x];
		}else{
			par[y] = x;
			sz[x]+=sz[y];
			if(rank[x] == rank[y])rank[x]++;
		}	
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	int size(int x){
		return sz[find(x)];
	}
	int query(int x,int y){
		if(same(x,y))return size(x);
		else return size(x)+size(y);
	}
}uf;
int N,M,Q;
int a[100100],b[100100];
int l[100100],r[100100];
int x[100100],y[100100],z[100100];
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> a[i] >> b[i];
		a[i]--;b[i]--;
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> x[i] >> y[i] >> z[i];
		x[i]--;y[i]--;
		l[i]=-1;r[i]=M-1;
	}
	while(1){
		vector<P> v;
		for(int i=0;i<Q;i++){
			if(r[i]-l[i]>1){
				v.pb(P((l[i]+r[i])/2,i));
			}
		}
		if(v.size()==0)break;
		sort(all(v));
		int id = 0;
		uf.init(N);
		for(int i=0;i<M;i++){
			uf.unite(a[i],b[i]);
			while(id<v.size()&&v[id].fi==i){
				int qid = v[id].sec;
				if(uf.query(x[qid],y[qid])>=z[qid])r[qid]=i;
				else l[qid]=i;
				id++;
			}
		}
	}
	for(int i=0;i<Q;i++)printf("%d\n",r[i]+1);
	return 0;
}