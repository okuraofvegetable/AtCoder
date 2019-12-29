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
vector<string> buf;
bool found;
void dfs(int a,int b,int c,vector<string> &f,vector<int> &tate,vector<int> &yoko){
  int n = f.size();
  if(found)return;
  if(c==2*n){
    for(int i=0;i<n;i++){
      if(tate[i]!=3)return;
      if(yoko[i]!=3)return;
    }
    buf = f;
    found = true;
    return;
  }
  for(int i=a;i<n;i++){
    for(int j=(i==a?b+1:0);j<n;j++){
      if( i+1<n && f[i][j]=='.' && f[i+1][j]=='.' && tate[i]<3 && tate[i+1]<3 && yoko[j]<3){
        tate[i]++;
        tate[i+1]++;
        yoko[j]++;
        f[i][j] = ('a'+c);
        f[i+1][j] = ('a'+c);
        dfs(i,j,c+1,f,tate,yoko);
        tate[i]--;
        tate[i+1]--;
        yoko[j]--;
        f[i][j] = '.';
        f[i+1][j] = '.';
      }
      if( j+1<n && f[i][j]=='.' && f[i][j+1]=='.' && tate[i]<3 && yoko[j]<3 && yoko[j+1]<3){
        tate[i]++;
        yoko[j]++;
        yoko[j+1]++;
        f[i][j] = ('a'+c);
        f[i][j+1] = ('a'+c);
        dfs(i,j,c+1,f,tate,yoko);
        tate[i]--;
        yoko[j]--;
        yoko[j+1]--;
        f[i][j] = '.';
        f[i][j+1] = '.';
      }
    }
  }
  return;
}
void print(vector<string> vec){
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << endl;
  }
  return;
}
vector<string> pattern(int n){
  vector<string> ret(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ret[i] += '.';
    }
  }
  vector<int> t(n,0),y(n,0);
  found = false;
  dfs(0,-1,0,ret,t,y);
  if(found)return buf;
  else assert(false);
}
void paste(vector<string> &pat,vector<string> &f,int a,int b){
  for(int i=0;i<pat.size();i++){
    for(int j=0;j<pat.size();j++){
      f[i+a][j+b] = pat[i][j];
    }
  }
}
signed main(){
  fastio();
  int n;
  cin >> n;
  if(n==2){
    cout << -1 << endl;
    return 0;
  }
  vector<string> ans(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ans[i] += '.';
    }
  }
  if(n%3==0){
    for(int i=0;i<n/3;i++){
        int x = i*3;
        int y = i*3;
        ans[x][y] = 'a';
        ans[x][y+1] = 'a';
        ans[x+1][y+2] = 'b';
        ans[x+2][y+2] = 'b';
    }
    for(int i=0;i<n;i++){
      cout << ans[i] << endl;
    }
    return 0;
  }
  vector<string> pat4 = pattern(4);
  // print(pat4);
  vector<string> pat5 = pattern(5);
  // print(pat5);
  vector<string> pat7 = pattern(7);
  // print(pat7);
  int s = n/4;
  int r = n%4;
  if(r==0){
    for(int i=0;i<s;i++){
      paste(pat4,ans,4*i,4*i);
    }
  }else if(r==1){
    for(int i=0;i<s-1;i++){
      paste(pat4,ans,4*i,4*i);
    }
    paste(pat5,ans,n-5,n-5);
  }else if(r==2){
    for(int i=0;i<s-2;i++){
      paste(pat4,ans,4*i,4*i);
    }
    paste(pat5,ans,n-10,n-10);
    paste(pat5,ans,n-5,n-5);
  }else if(r==3){
    for(int i=0;i<s-1;i++){
      paste(pat4,ans,4*i,4*i);
    }
    paste(pat7,ans,n-7,n-7);
  }
  print(ans);

  return 0;
}
