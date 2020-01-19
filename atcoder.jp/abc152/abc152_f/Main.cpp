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
#define INF 2000000000 //2e9
#define LLINF 1000000000000000ll // 1e15
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
    ModInt& operator+=(const ModInt& x){if((val+=x.val)>=MOD)val-=MOD;return *this;}
    ModInt& operator-=(const ModInt& x){if((val+=MOD-x.val)>=MOD)val-=MOD;return *this;}
    ModInt& operator*=(const ModInt& x){(val*=x.val)%=MOD;return *this;}
    ModInt operator+(const ModInt& x)const{return ModInt(*this)+=x;}
    ModInt operator-(const ModInt& x)const{return ModInt(*this)-=x;}
    ModInt operator*(const ModInt& x)const{return ModInt(*this)*=x;}
    friend istream& operator>>(istream&i,ModInt& x){ll v;i>>v;x=v;return i;}
    friend ostream& operator<<(ostream&o,const ModInt& x){o<<x.val;return o;}
  };

  template<int MOD>
  ModInt<MOD> pow(ModInt<MOD> a,ll x){
    ModInt<MOD> res = ModInt<MOD>(1ll);
    while(x){
      if(x&1)res *= a;
      x >>= 1;
      a = a*a;
    }
    return res;
  }

  constexpr int MOD = 1e9+7;
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
    while(x){
      x /= T(10);
      res++;
    }
    return res;
  }
}

namespace DS{
  template<class T>
  struct RangeSum{
    vector<T> vec;
    RangeSum(){}
    RangeSum(vector<T> elems):vec(elems){
      for(int i=1;i<vec.size();i++){
        vec[i] += vec[i-1];
      }
    }
    T sum(int l,int r){
      if(l>r)return T(0);
      if(l==0)return vec[r];
      else return vec[r]-vec[l-1];
    }
  };
  template<class T>
  struct BIT{
    int N;
    vector<T> bit;
    BIT(int N):N(N){
      bit = vector<T>(N+1,T(0));
    }
    void add(int i,T x){
      i++;
      while(i<=N){
        bit[i]+=x;
        i+=i&-i;
      }
      return;
    }
    T sum(int i){
      i++;
      T res = T(0);
      while(i>0){
        res+=bit[i];
        i-=i&-i;
      }
      return res;
    }
    T sum(int l,int r){// [l,r]
      assert(l<=r);
      if(l==0)return sum(r);
      else return sum(r)-sum(l-1);
    }
  };
  template<class T>
  struct SlideMin{
    vector<T> v;
    deque<int> deq;
    SlideMin(vector<T> &v):v(v){}
    void add(int id){
      while(!deq.empty()&&v[deq.back()]>=v[id])deq.pop_back();
      deq.push_back(id);
    }
    T get(int id){ // [id,added]
      while(!deq.empty()&&deq.front()<id)deq.pop_front();
      assert(!deq.empty());
      return v[deq.front()];
    }
  };
  template<class T>
  struct SlideMax{
    vector<T> v;
    deque<int> deq;
    SlideMax(vector<T> &v):v(v){}
    void add(int id){
      while(!deq.empty()&&v[deq.back()]<=v[id])deq.pop_back();
      deq.push_back(id);
    }
    T get(int id){ // [id,added]
      while(!deq.empty()&&deq.front()<id)deq.pop_front();
      assert(!deq.empty());
      return v[deq.front()];
    }
  };
}

namespace Util{
  template<class T>
  vector<pair<T,int>> runLength(vector<T> v){
    vector<pair<T,int>> res;
    for(int i=0;i<v.size();i++){
      if(res.empty()||res.back().first!=v[i])res.push_back(make_pair(v[i],1));
      else res.back().second++;
    }
    return res;
  }
  template<class T>
  void compress(vector<T> &v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
  }
}

struct edge{
  int to,id;
  edge(){}
  edge(int to,int id):to(to),id(id){}
};
vector<vector<edge>> G;
vector<int> u,v;
bitset<50> path[22];
bool used[100];
int t;
void dfs(int v,int g,vector<int>& h){
  used[v] = true;
  if(v==g){
    for(int i=0;i<h.size();i++){
      path[t].set(h[i]);
    }
    return ;
  }
  for(auto e : G[v]){
    if(!used[e.to]){
      h.pb(e.id);
      dfs(e.to,g,h);
      h.pop_back();
    }
  }
  return ;
}
signed main(){
  fastio();
  int N;
  cin >> N;
  G.resize(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    G[a].emplace_back(b,i);
    G[b].emplace_back(a,i);
  }
  int M;
  cin >> M;
  u.resize(M);
  v.resize(M);
  for(int i=0;i<M;i++){
    cin >> u[i];
    cin >> v[i];
    u[i]--;v[i]--;
    vector<int> vec;
    t = i;
    memset(used,false,sizeof(used));
    dfs(u[i],v[i],vec);
    // cout << path[i] << endl;
  }
  ll ans = (1ll<<(N-1));
  for(int i=1;i<(1<<M);i++){
    bitset<50> b;
    int cnt = 0;
    for(int j=0;j<M;j++){
      if((i>>j)&1){
        b |= path[j];
        cnt++;
      }
    }
    ll free = N-1-b.count();
    if(cnt%2==1)ans -= (1ll<<free);
    else ans += (1ll<<free);
  }
  cout << ans << endl;
  return 0;
}
