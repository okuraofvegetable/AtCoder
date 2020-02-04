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
#define INF 1000000000 //1e9
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

  constexpr int MOD = 1e9+7;
  // constexpr int MOD = 998244353;
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
  template<class T>
  int digit_sum(T x){
    int res = 0;
    while(x){ res+=x%10; x/=10; }
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
  template<class D,class O>
  struct LazySegmentTree{
    using DMerger = function<D(D,D)>;
    using OMerger = function<O(O,O)>;
    using Applier = function<D(D,O,int)>;

    int length;

    D d_unit;
    O o_unit;

    vector<D> seg;
    vector<O> lazy;

    DMerger dm;
    OMerger om;
    Applier app;

    void lazy_evaluate(int k,int len){
      if(lazy[k] == o_unit) return;
      if(len>1){
        lazy[2*k+1] = om(lazy[2*k+1],lazy[k]);
        lazy[2*k+2] = om(lazy[2*k+2],lazy[k]);
      }
      seg[k] = app(seg[k],lazy[k],len);
      lazy[k] = o_unit;
    }
    void update(int a,int b,int k,int l,int r,O x){
      lazy_evaluate(k,r-l);
      if(r<=a||b<=l)return;
      else if(a<=l&&r<=b){
        lazy[k] = om(lazy[k],x);
        lazy_evaluate(k,r-l);
      }else{
        update(a,b,k*2+1,l,(l+r)/2,x);
        update(a,b,k*2+2,(l+r)/2,r,x);
        seg[k] = dm(seg[k*2+1],seg[k*2+2]);
      }
    }
    void update(int a,int b,O x){
      update(a,b,0,0,length,x);
    }
    D query(int a,int b,int k,int l,int r){
      lazy_evaluate(k,r-l);
      if(r<=a||b<=l)return d_unit; 
      else if(a<=l&&r<=b)return seg[k];
      else{
        D lch = query(a,b,k*2+1,l,(l+r)/2);
        D rch = query(a,b,k*2+2,(l+r)/2,r);
        return dm(lch,rch);
      }
    }
    D query(int a,int b){
      return query(a,b,0,0,length);
    }
    LazySegmentTree(int n,D d_unit,O o_unit,DMerger dm,OMerger om,Applier app)
      :length(1),d_unit(d_unit),o_unit(o_unit),dm(dm),om(om),app(app) {
      while(length<n){ length <<= 1; }
      seg.assign(length * 2, d_unit);
      lazy.assign(length * 2, o_unit);
    }
    LazySegmentTree(vector<D> vec,D d_unit,O o_unit,DMerger dm,OMerger om,Applier app)
      :length(1),d_unit(d_unit),o_unit(o_unit),dm(dm),om(om),app(app) {
      while(length<vec.size()){ length <<= 1; }
      seg.assign(length * 2, d_unit);
      lazy.assign(length * 2, o_unit);
      for(int i=0;i<vec.size();i++)seg[length-1+i] = vec[i];
      for(int i=length-2;i>=0;i--)seg[i] = dm(seg[i*2+1],seg[i*2+2]);
    }
  };
  // RangeAddRangeSum update : a[l,r) += c
  // verified https://atcoder.jp/contests/abc153/submissions/9866001
  template<class T>
  LazySegmentTree<T,T> RangeAddRangeSum(int size){
    auto dm = [](T a,T b){return a+b;};
    auto om = [](T a,T b){return a+b;};
    auto app = [](T dat,T lz,int len){return dat+lz*T(len);};
    return LazySegmentTree<T,T>(size,0ll,0ll,dm,om,app);
  }
  template<class T>
  LazySegmentTree<T,T> RangeAddRangeSum(vector<T> vec){
    auto dm = [](T a,T b){return a+b;};
    auto om = [](T a,T b){return a+b;};
    auto app = [](T dat,T lz,int len){return dat+lz*T(len);};
    return LazySegmentTree<T,T>(vec,0ll,0ll,dm,om,app);
  }
  // RangeAddRangeMin
  // NOT verified yet
  template<class T>
  LazySegmentTree<T,T> RangeAddRangeMin(int size){
    auto dm = [](T a,T b){return min(a,b);};
    auto om = [](T a,T b){return a+b;};
    auto app = [](T dat,T lz,int len){return dat+lz;};
    return LazySegmentTree<T,T>(size,0ll,0ll,dm,om,app);
  }
  template<class T>
  LazySegmentTree<T,T> RangeAddRangeMin(vector<T> vec){
    auto dm = [](T a,T b){return min(a,b);};
    auto om = [](T a,T b){return a+b;};
    auto app = [](T dat,T lz,int len){return dat+lz;};
    return LazySegmentTree<T,T>(vec,0ll,0ll,dm,om,app);
  }
  // RangeAffineRangeSum update (l,r,(p,q)) : a[i] = p * a[i] + q { i in [l,r) }
  // verified https://judge.yosupo.jp/submission/3354
  template<class T>
  LazySegmentTree<ll,pair<T,T>> RangeAffineRangeSum(int size){
    using f = pair<T,T>;
    auto dm = [](T a,T b){return a+b;};
    auto om = [](f a,f b){return f(b.fi*a.fi,b.fi*a.sec+b.sec);};
    auto app = [](T dat,f lz,int len){return lz.fi*dat+lz.sec*T(len);};
    return LazySegmentTree<T,f>(size,T(0),f(T(1),T(0)),dm,om,app);
  }
  template<class T>
  LazySegmentTree<T,pair<T,T>> RangeAffineRangeSum(vector<T> vec){
    using f = pair<T,T>;
    auto dm = [](T a,T b){return a+b;};
    auto om = [](f a,f b){return f(b.fi*a.fi,b.fi*a.sec+b.sec);};
    auto app = [](T dat,f lz,int len){return lz.fi*dat+lz.sec*T(len);};
    return LazySegmentTree<T,f>(vec,T(0),f(T(1),T(0)),dm,om,app);
  }
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
template<class T>
T gcd(T x,T y){
  if(y==T(0))return x;
  else return gcd(y,x%y);
}

 
signed main(){
  fastio();
  int n;
  cin >> n;
  int ans = INF;
  for(int i=1;i<=n;i++){
    for(int j=1;i*j<=n;j++){
      chmin(ans,abs(i-j)+n-i*j);
    }
  }
  cout << ans << endl;
  return 0;
}
