#include <bits/stdc++.h>
using namespace std;
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
int N;
ll M,V,P;
vector<ll> a;
vector<ll> rui;
ll sum(int l,int r){
  if(l>=r)return 0ll;
  if(l==0)return rui[r];
  else return rui[r]-rui[l-1];
}
bool check(int k,int id){
  //cout << "k : " << k << " id : " << id  << endl;
  ll sel = max(0ll,V-(ll)k-(ll)id-1ll);
  //cout << "sel " << sel << endl;
  int u = upper_bound(all(a),a[id]+M)-a.begin();
  int R = N-k-1;
  int L = id+1;
  if(R>u-1)return false;
  //cout << "L R " << L << ' ' << R << endl;
  int width = R-L+1;
  ll rem = (a[id]+M)*(ll)width - sum(L,R);
  //cout << "rem " << rem << endl;
  return rem >= sel*M;
}
bool solve(int id){
  int l = -1,r = N-id-1;
  while(r-l>1){
    int mid = (l+r)/2;
    if(check(mid,id))r = mid;
    else l = mid;
  }
  //cout << "r " <<  r << endl;
  return (r<P);
}
signed main(){
  fastio();
  cin >> N >> M >> V >> P;
  a.resize(N);
  cin >> a;
  sort(all(a));
  rui.resize(N);
  for(int i=0;i<N;i++){
    if(i==0)rui[i] = a[i];
    else rui[i] = a[i] + rui[i-1];
  }
  //cout << rui << endl;
  int ans = 0;
  for(int i=0;i<N;i++){
    if(solve(i))ans++;
  }
  //cout << "a ";
  //cout << a << endl;
  //check(1,0);
  cout << ans << endl;
  return 0;
}
