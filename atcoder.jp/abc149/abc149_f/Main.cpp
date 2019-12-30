#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
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
ostream& operator << (ostream& os,const pair<T,U>& p){
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
const ll MOD = 1000000007ll; // if inv is needed, this shold be prime.
struct ModInt{
	ll val;
	ModInt():val(0ll){}
	ModInt(const ll& v):val(((v%MOD)+MOD)%MOD){}
	ModInt exp(ll y)const{
		if(!y)return ModInt(1ll);
		ModInt a = exp(y/2ll);
		a *= a;
		if(y&1)a*=(*this);
		return a;
	}
	bool operator==(const ModInt& x)const{return val==x.val;}
	inline bool operator!=(const ModInt& x)const{return !(*this==x);}
	bool operator<(const ModInt& x)const{return val<x.val;}
	bool operator>(const ModInt& x)const{return val>x.val;}
	inline bool operator>=(const ModInt& x)const{return !(*this<x);}
	inline bool operator<=(const ModInt& x)const{return !(*this>x);}
	ModInt& operator+=(const ModInt& x){if((val+=x.val)>=MOD)val-=MOD;return *this;}
	ModInt& operator-=(const ModInt& x){if((val+=MOD-x.val)>=MOD)val-=MOD;return *this;}
	ModInt& operator*=(const ModInt& x){(val*=x.val)%=MOD;return *this;}
	ModInt operator+(const ModInt& x)const{return ModInt(*this)+=x;}
	ModInt operator-(const ModInt& x)const{return ModInt(*this)-=x;}
	ModInt operator*(const ModInt& x)const{return ModInt(*this)*=x;}
  friend istream& operator>>(istream&i,ModInt& x){ll v;i>>v;x=v;return i;}
  friend ostream& operator<<(ostream&o,const ModInt& x){o<<x.val;return o;}
};
ModInt pow(ModInt a,ll x){
  ModInt res = ModInt(1ll);
  while(x){
    if(x&1)res *= a;
    x >>= 1;
    a = a*a;
  }
  return res;
}
vector<ModInt> inv,fac,facinv;
// notice: 0C0 = 1 
ModInt nCr(int n,int r){
	assert(!(n<r));
	assert(!(n<0||r<0));
	return fac[n]*facinv[r]*facinv[n-r];
}
void init(int SIZE){
  fac.resize(SIZE+10);
  inv.resize(SIZE+10);
  facinv.resize(SIZE+10);
	fac[0]=ModInt(1ll);
	for(int i=1;i<=SIZE;i++)fac[i]=fac[i-1]*ModInt(i);
	inv[1]=ModInt(1ll);
	for(int i=2;i<=SIZE;i++)inv[i]=ModInt(0ll)-ModInt(MOD/i)*inv[MOD%i];
	facinv[0]=ModInt(1ll);
	for(int i=1;i<=SIZE;i++)facinv[i]=facinv[i-1]*inv[i];
	return;
}
struct edge{
	int from,to;
	edge(){}
	edge(int f,int t):from(f),to(t){}
};
struct Tree{
	int V;
	int LOG_V;
	int root;
	vector<int> depth;
	vector<vector<int> > dpar;
	vector<int> par;
	vector<int> subtree_size;
	vector<int> centroid;
	vector<vector<edge> > G;
	Tree(){}
	Tree(int v,int r=0){
		V = v;
		root = r;
		G.resize(V);
		depth.resize(V);
		par.resize(V);
		subtree_size.resize(V);
		/* for doubling
		LOG_V = 1;
		while((1<<LOG_V)<=V)LOG_V++;
		dpar.resize(LOG_V);
		for(int i=0;i<LOG_V;i++)dpar[i].resize(V,-1);
		*/
	}
	void add_edge(int u,int v){
		G[u].pb(edge(u,v));
		G[v].pb(edge(v,u));
	}
	int dfs(int v,int p,int d){
		depth[v]=d;
		par[v]=p;
		subtree_size[v]=1;
		bool is_centroid = true;
		for(int i=0;i<G[v].size();i++){
			int u = G[v][i].to;
			if(u==p)continue;
			subtree_size[v]+=dfs(u,v,d+1);
			if(subtree_size[u]>V/2)is_centroid=false;
		}
		if(V-subtree_size[v]>V/2)is_centroid=false;
		if(is_centroid)centroid.pb(v);
		return subtree_size[v];
	}
	void dfs(){
		dfs(root,-1,0);
	}
	void construct_dpar(){
		for(int i=0;i<V;i++)dpar[0][i] = par[i];
		for(int i=1;i<LOG_V;i++){
			for(int j=0;j<V;j++){
				if(dpar[i-1][j]==-1)dpar[i][j]=-1;
				else dpar[i][j] = dpar[i-1][dpar[i-1][j]];
			}
		}
		return;
	}
	int kth_parent(int v,int k){
		int res = v;
		for(int i=0;i<LOG_V;i++){
			if(k&(1<<i))res = dpar[i][res];
			if(res==-1)return -1;
		}
		return res;
	}
	void dump_tree(){
		for(int i=0;i<V;i++){
			printf("id: %d, par %d, depth %d\n",i,par[i],depth[i]);
		}
		return;
	}
};
ModInt pow_inv2[200100];
ModInt pow_2[200100];
signed main(){
  fastio();
  init(200100);
  pow_inv2[0] = ModInt(1ll);
  pow_2[0] = ModInt(1ll);
  for(int i=1;i<=200000;i++){
    pow_inv2[i] = pow_inv2[i-1] * inv[2];
    pow_2[i] = pow_2[i-1] * ModInt(2ll);
  }
  int N;
  cin >> N;
  Tree G(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    G.add_edge(a,b);
  }
  G.dfs();
  //G.dump_tree();
  ModInt ans;
  for(int i=0;i<N;i++){
    if(G.G[i].size()==1)continue;
    vector<int> sz;
    int p = N-1;
    bool flag = false;
    for(auto e : G.G[i]){
      if(G.par[i]==e.to){
        flag = true;
      }else{
        sz.pb(G.subtree_size[e.to]);
        p -= G.subtree_size[e.to];
      }
    }
    sz.push_back(p);
    ModInt allwhite = ModInt(1ll);
    for(int i=0;i<sz.size();i++){
      allwhite *= pow_inv2[sz[i]];
    }
    ModInt onewhite = ModInt(0ll);
    for(int i=0;i<sz.size();i++){
      onewhite += allwhite * pow_2[sz[i]] * (ModInt(1ll) - pow_inv2[sz[i]]);
    }
    ans += inv[2] * (ModInt(1ll) - allwhite - onewhite);
  }
  cout << ans << endl;
  return 0;
}
