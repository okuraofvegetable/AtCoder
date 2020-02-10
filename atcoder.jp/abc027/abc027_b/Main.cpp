#include <bits/stdc++.h>
using namespace std; typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000 //2e9
#define LLINF 100000000000000000ll // 1e17
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define dmp(x) cerr << #x << ": " << x << endl;

template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T,vector<T>,greater<T>>;
template<class T> vector<T> vect(int len,T elem){ return vector<T>(len,elem); }

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

namespace Math{
  template<int MOD> // if inv is needed, this shold be prime.
  struct ModInt{
    ll val;
    ModInt():val(0ll){}
    ModInt(const ll& v):val(((v%MOD)+MOD)%MOD){}
    bool operator==(const ModInt& x)const{return val==x.val;}
    bool operator!=(const ModInt& x)const{return !(*this==x);}
    bool operator<(const ModInt& x)const{return val<x.val;}
    bool operator>(const ModInt& x)const{return val>x.val;}
    bool operator>=(const ModInt& x)const{return !(*this<x);}
    bool operator<=(const ModInt& x)const{return !(*this>x);}
    ModInt operator-()const{return ModInt(MOD-val);}
    ModInt inv()const{return this->pow(MOD-2);}
    ModInt& operator+=(const ModInt& x){if((val+=x.val)>=MOD)val-=MOD;return *this;}
    ModInt& operator-=(const ModInt& x){if((val+=MOD-x.val)>=MOD)val-=MOD;return *this;}
    ModInt& operator*=(const ModInt& x){(val*=x.val)%=MOD;return *this;}
    ModInt& operator/=(const ModInt& x){return *this *= x.inv();};
    ModInt operator+(const ModInt& x)const{return ModInt(*this)+=x;}
    ModInt operator-(const ModInt& x)const{return ModInt(*this)-=x;}
    ModInt operator*(const ModInt& x)const{return ModInt(*this)*=x;}
    ModInt operator/(const ModInt& x)const{return ModInt(*this)/=x;}
    friend istream& operator>>(istream&i,ModInt& x){ll v;i>>v;x=v;return i;}
    friend ostream& operator<<(ostream&o,const ModInt& x){o<<x.val;return o;}
    ModInt pow(ll x)const{
      auto res = ModInt(1ll);
      auto b = *this;
      while(x){
        if(x&1)res *= b;
        x >>= 1;
        b *= b;
      }
      return res;
    }
  };

  template<int MOD>
  ModInt<MOD> pow(ModInt<MOD> a,ll x){
    ModInt<MOD> res = ModInt<MOD>(1ll);
    while(x){
      if(x&1)res *= a;
      x >>= 1;
      a *= a;
    }
    return res;
  }

  // constexpr int MOD = 1e9+7;
  constexpr int MOD = 998244353;
  using mint = ModInt<MOD>;

  vector<mint> inv,fac,facinv;
  // notice: 0C0 = 1 
  ModInt<MOD> nCr(int n,int r){
    assert(!(n<r));
    assert(!(n<0||r<0));
    return fac[n]*facinv[r]*facinv[n-r];
  }
  void init(int SIZE){
    fac.resize(SIZE+1);
    inv.resize(SIZE+1);
    facinv.resize(SIZE+1);
    fac[0] = inv[1] = facinv[0] = mint(1ll);
    for(int i=1;i<=SIZE;i++)fac[i]=fac[i-1]*mint(i);
    for(int i=2;i<=SIZE;i++)inv[i]=mint(0ll)-mint(MOD/i)*inv[MOD%i];
    for(int i=1;i<=SIZE;i++)facinv[i]=facinv[i-1]*inv[i];
    return;
  }
  template<class T>
  int digit(T x){
    int res = 0;
    while(x){ x /= T(10); res++; }
    return res;
  }
  template<class T>
  int digit_sum(T x){
    int res = 0;
    while(x){ res+=x%10; x/=10; }
    return res;
  }
  template<class T>
  T gcd(T x,T y){
    if(y==T(0))return x;
    else return gcd(y,x%y);
  }
}

template<class Cost>
struct edge{
  int from,to;
  Cost cost;
  edge(){}
  edge(int from,int to,Cost cost):from(from),to(to),cost(cost){}

  // for debug
  friend ostream& operator << (ostream& os,const edge& e) {
    os << e.from << " -> " << e.to << " : " << e.cost << ", ";
    return os;
  }
};

template<class Cost>
struct Graph{
  int V;
  vector<vector<edge<Cost>>> G;
  explicit Graph(int V):V(V){
    G.resize(V);
  }
  void add_edge(int a,int b,Cost cost = Cost(0)){
    G[a].push_back(edge<Cost>(a,b,cost));
  }
  void add_edge_undirected(int a, int b, Cost cost = Cost(0)){
    G[a].push_back(edge<Cost>(a,b,cost));
    G[b].push_back(edge<Cost>(b,a,cost));
  }
  size_t size() const { return G.size(); }
  const vector<edge<Cost>>& operator [] (int id) const {
    return G[id];
  }

  vector<Cost> dijkstra(int s){
    assert(0<=s&&s<G.size());
    vector<Cost> dist;
    dist.assign(G.size(),numeric_limits<Cost>::max());
    dist[s] = Cost(0);
    MinHeap<pair<Cost,int>> q;    
    q.push(make_pair(Cost(0),s));
    while(!q.empty()){
      auto a = q.top();
      q.pop();
      int v = a.second;
      if(dist[v]<a.first)continue;
      for(auto e : G[v]){
        if(dist[e.to] > dist[v]+e.cost){
          dist[e.to] = dist[v]+e.cost;
          q.push(make_pair(dist[e.to],e.to));
        }
      }
    }
    return dist;
  }

  // for debug
  friend ostream& operator << (ostream& os, const Graph g) {
    for(int i=0;i<g.size();i++){
      os << g[i];
      if(i+1<g.size())os << endl;
    }
    return os;
  }
};

using namespace Math;

signed main(){
  int N;
  cin >> N;
  vector<int> a(N);
  cin >> a;
  int s = accumulate(all(a),0);
  if(s%N!=0){
    cout << -1 << endl;
    return 0;
  }
  int r = s/N;
  int ans = 0;
  int sum = 0;
  for(int i=0;i<N;i++){
    sum += a[i];
    if(r*(i+1)!=sum)ans++;
  }
  cout << ans << endl;
  return 0;
}
