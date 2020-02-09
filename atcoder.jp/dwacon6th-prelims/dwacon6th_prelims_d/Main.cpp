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
bool check(vector<int>& v,vector<int>& a){
  for(int i=0;i+1<v.size();i++){
    if(v[i+1]==a[v[i]])return false;
  }
  return true;
}

signed main(){
  int N;
  cin >> N;
  vector<int> deg(N,0);
  vector<int> hate();
  vector<int> a(N);
  vector<set<int>> deg_list(N+1,set<int>());
  set<int> rem;
  cin >> a;
  for(int i=0;i<N;i++){
    a[i]--;
    deg[a[i]]++;
    rem.insert(i);
  }
  for(int i=0;i<N;i++){
    deg_list[deg[i]].insert(i);
  }
  vector<int> ans;
  int ban = -1;
  for(int i=0;i<max(N-3,0);i++){
    if(deg_list[N-1-i].size()>1){
      cout << -1 << endl;
      return 0;
    }else if(deg_list[N-1-i].size()==1){
      int sel = *deg_list[N-1-i].begin();
      if(sel==ban){
        cout << -1 << endl;
        return 0;
      }
      ans.push_back(sel);
      ban = a[sel];
      rem.erase(sel);
      deg_list[deg[a[sel]]--].erase(a[sel]);
      deg_list[deg[a[sel]]].insert(a[sel]);
    }else{
      auto it = rem.begin();
      while(*it==ban&&it!=rem.end()){
        it++;
      }
      if(it==rem.end()){
        cout << -1 << endl;
        return 0;
      }
      int sel = *it;
      ans.push_back(sel);
      ban = a[sel];
      rem.erase(sel);
      deg_list[deg[a[sel]]--].erase(a[sel]);
      deg_list[deg[a[sel]]].insert(a[sel]);
    }
  }
  vector<int> rest;
  for(auto it = rem.begin();it!=rem.end();it++){
    rest.push_back(*it);
  } 
  do{
    vector<int> vall = ans;
    for(int i=0;i<rest.size();i++){
      vall.push_back(rest[i]);
    }
    if(check(vall,a)){
      for(int i=0;i<vall.size();i++){
        cout << vall[i]+1;
        if(i+1<vall.size())cout << ' ';
        else cout << endl;
      }
      return 0;
    }
  }while(next_permutation(all(rest)));
  cout << -1 << endl;
  return 0;
}
