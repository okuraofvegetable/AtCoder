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
#define LLINF 10000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define dmp(x) cerr << #x << ": " << x << endl;
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
namespace Math{
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
  template<class T,int N>
  struct BIT{
    vector<T> bit;
    BIT(){
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
}
ll mygcd(ll x,ll y){
  if(y==0ll)return x;
  else return mygcd(y,x%y);
}
int f(ll x){
  int res = 0;
  while(x%2==0){
    x/=2;
    res++;
  }
  return res;
}
int N;
ll M;
signed main(){
  fastio();
  cin >> N >> M;
  vector<ll> a(N);
  cin >> a;
  ll g = 1ll;
  for(int i=0;i<N;i++){
    a[i]/=2;
  }
  for(int i=0;i<N;i++){
    if(f(a[i])!=f(a[0])){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i=0;i<N;i++){
    g = g/mygcd(a[i],g)*a[i];
    if(g>M){
      cout << 0 << endl;
      return 0;
    }
  } 
  cout << (M/g+1)/2 << endl;
  return 0;
}
