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
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
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
}

namespace Util{
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

signed main(){
  fastio();
  int N;
  cin >> N;
  vi A(N),B(N);
  cin >> A;
  cin >> B;
  int ans = INF;
  for(int i=0;i<(1<<N);i++){
    //dmp(i);
    vector<P> v;
    vector<int> num;
    for(int j=0;j<N;j++){
      if((i>>j)&1){
        v.pb(P(B[j],1));
        num.pb(B[j]);
      }
      else{
        v.pb(P(A[j],0));
        num.pb(A[j]);
      }
    }
    sort(all(num));
    //dmp(v);
    //dmp(num);
    int cnt = 0;
    bool fail = false;
    for(int j=0;j<N;j++){
      if(v[j]==P(num[j],0))continue;
      int found = -1;
      for(int k=j+1;k<N;k++){
        if(v[k].fi==num[j]&&v[k].sec%2==(k-j)%2){
          found = k;
          break;
        }
      }
      if(found==-1){
        fail = true;
        break;
      }
      for(int k=found;k>j;k--){
        swap(v[k],v[k-1]);
        v[k].second ^= 1;
        v[k-1].second ^= 1;
        cnt++;
      }
    }
    //dmp(fail);
    //dmp(cnt);
    if(!fail)ans = min(ans,cnt);
  }
  if(ans==INF)cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
