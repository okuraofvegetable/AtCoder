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
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;} template<class T>
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
const int SIZE = 1<<18;
struct segtree{
  pair<ll,int> seg[SIZE*2];
  ll lazy[SIZE*2];
  void lazy_evaluate(int k){
    seg[k].fi += lazy[k];
    if(k<SIZE-1){
      lazy[k*2+1] += lazy[k];
      lazy[k*2+2] += lazy[k];
    }
    lazy[k] = 0ll;
  }
  void update(int a,int b,int k,int l,int r,ll x){
    lazy_evaluate(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
      lazy[k] += x;
      lazy_evaluate(k);
    }else{
      int mid = (l+r)/2;
      update(a,b,k*2+1,l,mid,x);
      update(a,b,k*2+2,mid,r,x);
      seg[k] = min(seg[k*2+1],seg[k*2+2]);
      return;
    }
  }
  void update(int a,int b,ll x){
    if(b<=a)return;
    update(a,b,0,0,SIZE,x);
  }
  pair<ll,int> query(int a,int b,int k,int l,int r){
    lazy_evaluate(k);
    if(r<=a||b<=l)return make_pair(LLINF,-1);
    else if(a<=l&&r<=b)return seg[k];
    else{
      int mid = (l+r)/2;
      pair<ll,int> lch = query(a,b,k*2+1,l,mid);
      pair<ll,int> rch = query(a,b,k*2+2,mid,r);
      return min(lch,rch);
    }
  }
  pair<ll,int> query(int a,int b){
    return query(a,b,0,0,SIZE);
  }
  void build(vector<ll> &v){
    for(int i=0;i<SIZE;i++){
      if(i<v.size())seg[SIZE-1+i]=make_pair(v[i],i);
      else seg[SIZE-1+i]=make_pair(LLINF,i);
    }
    for(int i=SIZE-2;i>=0;i--){
      seg[i] = min(seg[i*2+1],seg[i*2+2]);
    }
    return;
  }
}seg;
int N,M;
string s;
int nxt[100100];
signed main(){
  fastio();
  cin >> N >> M;
  cin >> s;
  vector<ll> dp;
  for(int i=0;i<N;i++)dp.pb(0ll);
  dp.pb(0ll);
  seg.build(dp);
  for(int i=N-1;i>=0;i--){
    if(s[i]=='1'){
      seg.update(i,i+1,LLINF);
    }else{
      pair<ll,int> q = seg.query(i+1,min(i+M+1,N+1));
      dp[i] = q.first+1;
      nxt[i] = q.sec-i;
      seg.update(i,i+1,q.first+1);
    }
  }
  if(dp[0]>=LLINF){
    cout << -1 << endl;
    return 0;
  }
  int cur = 0;
  vector<int> ans;
  while(cur<N){
    ans.pb(nxt[cur]);
    cur += nxt[cur];
  }
  for(int i=0;i<ans.size();i++){
    cout << ans[i];
    if(i+1<ans.size())cout << ' ';
    else cout << endl;
  }
  return 0;
}
