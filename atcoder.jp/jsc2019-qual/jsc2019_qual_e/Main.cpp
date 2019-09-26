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
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl;
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T,vector<T>,greater<T> >;
template<class T,class U>
ostream& operator << (ostream& os,pair<T,U>& p){
  os << p.fi << ',' << p.sec; return os;
}
template<class T,class U>
istream& operator >> (istream& is,pair<T,U>& p){
  is >> p.fi >> p.sec; return is;
}
template<class T>
ostream& operator << (ostream &os,const vector<T> &vec){
  for(int i=0;i<vec.size();i++){
    os << vec[i];
    if(i+1<vec.size())os << ' ';
  }
  return os;
}
template<class T>
istream& operator >> (istream &is,vector<T>& vec){
  for(int i=0;i<vec.size();i++)is >> vec[i];
  return is;
}
void fastio(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout<<fixed<<setprecision(20);
}
struct UnionFind{
	vector<int> par,rank,sz;
	void init(int n){
    par.resize(n);
    sz.resize(n,1);
    rank.resize(n,0);
		for(int i=0;i<n;i++){
			par[i] = i;
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
    par[x] = y;
    sz[y] += sz[x];
    rank[y] += rank[x];
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
}uf;
int N;
int H,W;
struct edge{
  int f,t;
  ll c;
  edge(){}
  edge(int f,int t,int c):f(f),t(t),c(c){}
  bool operator < (const edge& a) const{
    return c > a.c;
  }
};
vector<edge> es;
int main(){
  fastio();
  cin >> N >> H >> W;
  uf.init(H+W);
  for(int i=0;i<N;i++){
    int r,c,a;
    cin >> r >> c >> a;
    r--;c--;
    c += H;
    es.pb(edge(r,c,a));
  }
  sort(all(es));
  ll ans = 0ll;
  for(int i=0;i<es.size();i++){
    edge e = es[i];
    int f = uf.find(e.f);
    int t = uf.find(e.t);
    if(f==t){
      if(uf.sz[f]>uf.rank[f]){
        ans += e.c;
        uf.rank[f]++;
      }
    }else{
      if(uf.sz[f]+uf.sz[t]>=uf.rank[f]+uf.rank[t]+1){
        ans += e.c;
        uf.unite(f,t);
        uf.rank[t]++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
