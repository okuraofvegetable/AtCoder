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
const ll MOD = 998244353ll; // if inv is needed, this shold be prime.
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
  friend ostream& operator<<(ostream&o,ModInt& x){o<<x.val;return o;}
  ModInt pow(ModInt a,ll x) const {
    ModInt res = ModInt(1ll);
    while(x){
      if(x&1)res *= a;
      x >>= 1;
      a = a*a;
    }
    return res;
  }
};
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
int N;
string X;
const int M = 15;
int f(int x){
  int all_mask = (1<<M)-1;
  for(int i=1;i<=M;i++){
    int mask = (1<<i)-1;
    int low = (((x&mask)^mask)<<(M-i));
    int ret = (all_mask^(low^(x>>i)));
    if(ret==x){
      return i;
    }
  }
  return -1;
}
string bitrev(string s){
  string t;
  for(int i=0;i<s.size();i++){
    if(s[i]=='1')t+='0';
    else t+='1';
  }
  return t;
}
ModInt one = ModInt(1ll);
ModInt to_ModInt(string s){
  ModInt a;
  for(int i=0;i<s.size();i++){
    a = a*ModInt(2ll);
    if(X[i]=='1')a += one;
  }
  return a;
}  
ModInt solve(int x){
  string s = X.substr(0,x);
  string t = bitrev(s);
  ModInt a = to_ModInt(s);
  // cout << s << endl;
  // cout << a << endl;
  ModInt res;
  res += a;
  string c;
  for(int i=0;i<N/x;i++){
    if(i%2==0)c+=s;
    else c+=t;
  }
  // cout << c << endl;
  // cout << X << endl;
  // cout << res << endl;
  if(c>X)return res;
  else return (res+one);
}
int main(){
  fastio();
  cin >> N;
  cin >> X;
  vector<int> fac;
  for(int i=1;i<N;i++){
    if(N%i!=0)continue;
    if((N/i)%2==1){
      fac.pb(i);
      // cout << i << endl;
    }
  }
  // for(int i=0;i<(1<<M);i++){
  //   int res = f(i);
  //   if(res!=M)cout << bitset<15>(i)  << ' ' << f(i) << endl;
  // }
  ModInt All = to_ModInt(X)+one;
  //cout << All << endl;
  ModInt ans;
  vector<ModInt> vec;
  for(int i=0;i<fac.size();i++){
    ModInt d = solve(fac[i]);
    // cout << fac[i] << ' ' << d << endl;
    vec.pb(d);
  }
  for(int i=0;i<vec.size();i++){
    for(int j=i+1;j<vec.size();j++){
      if(fac[j]%fac[i]==0){
        vec[j]-=vec[i];
      }
    }
  }
  for(int i=0;i<fac.size();i++){
    // cout << fac[i] << ' ' << vec[i] << endl;
    All -= vec[i];
    ans += vec[i]*ModInt(fac[i]);
  }
  ans += All*ModInt(N);
  ans *= ModInt(2ll);
  cout << ans << endl;
  return 0;
}
