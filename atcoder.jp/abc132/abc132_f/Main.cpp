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
ll MOD = 1000000007ll; // if inv is needed, this shold be prime.
struct ModInt{
	ll val;
	ModInt():val(0ll){}
	ModInt(ll v):val(((v%MOD)+MOD)%MOD){}
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
};
istream& operator>>(istream&i,ModInt&x){i>>x.val;return i;}
ostream& operator<<(ostream&o,const ModInt&x){o<<x.val;return o;}
ModInt pow(ModInt a,ll x){
	ModInt res = ModInt(1ll);
	while(x){
		if(x&1)res *= a;
		x >>= 1;
		a = a*a;
	}
	return res;
}
const int SIZE = 100100;
ModInt inv[SIZE+10],fac[SIZE+10],facinv[SIZE+10];
// notice: 0C0 = 1 
ModInt nCr(int n,int r){
	assert(!(n<r));
	assert(!(n<0||r<0));
	return fac[n]*facinv[r]*facinv[n-r];
}
void init(){
	fac[0]=ModInt(1ll);
	for(int i=1;i<=SIZE;i++)fac[i]=fac[i-1]*ModInt(i);
	inv[1]=ModInt(1ll);
	for(int i=2;i<=SIZE;i++)inv[i]=ModInt(0ll)-ModInt(MOD/i)*inv[MOD%i];
	facinv[0]=ModInt(1ll);
	for(int i=1;i<=SIZE;i++)facinv[i]=facinv[i-1]*inv[i];
	return;
}
int B = 1;
ModInt dp[105][100100];
int N,K;
int idx(int x){
  if(x<=N/B)return x;
  int r = N/x;
  return N/B+B-r;
}
int main(){
  fastio();
  cin >> N >> K;
  while(B+1<N/B)B++;
  for(int i=1;i<=N/B;i++){
    dp[0][i] = ModInt(1ll);
  }
  for(int i=B-1;i>0;i--){
    dp[0][N/B+B-i] = N/i-N/(i+1);
  }
  for(int i=0;i<K-1;i++){
    for(int j=1;j<=N/B;j++){
      int mx = idx(N/j);
      // cout << mx << endl;
      dp[i+1][1] += dp[i][j];
      dp[i+1][mx+1] -= dp[i][j];
    }
    for(int j=B-1;j>0;j--){
      int k = N/B+B-j;
      int mx = idx(j);
      //cout << mx << endl;
      dp[i+1][1] += dp[i][k];
      dp[i+1][mx+1] -= dp[i][k];
    }
    //cout << "line " << i+1 << endl;
    for(int j=1;j<=N/B+B+2;j++){
      //cout << dp[i+1][j] << ' ';
      dp[i+1][j] += dp[i+1][j-1];
    }
    //cout << endl;
    for(int j=B-1;j>0;j--){
      int k = N/B+B-j;
      int num = N/j-N/(j+1);
      dp[i+1][k] *= ModInt(num);
    }
  }
  // for(int i=0;i<K;i++){
  //   for(int j=1;j<=N/B+B;j++){
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  ModInt ans;
  for(int i=1;i<N/B+B;i++){
    ans += dp[K-1][i];
  }
  cout << ans << endl;
  return 0;
}
