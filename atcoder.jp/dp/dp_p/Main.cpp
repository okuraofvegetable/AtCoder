#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
#define MOD 1000000007ll // prime
// How to devide :
// ModInt a(6ll);
// ModInt b(2ll);
// a *= b.exp(MOD-2ll);  -> a/=b;  result: a = 3
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
int N;
vector<int> g[100100];
ModInt dp[100100][2];
ModInt rec(int v,int p,int c){
	ModInt ret = ModInt(1ll);
	if(dp[v][c]!=ModInt(-1ll))return dp[v][c];
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==p)continue;
		int u = g[v][i];
		if(c==0)ret *= rec(u,v,!c);
		else ret *= (rec(u,v,c)+rec(u,v,!c));
	}
	return dp[v][c]=ret;
}
int main(){
	init();
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int x,y;
		cin >> x >> y;
		x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			dp[i][j]=ModInt(-1ll);
		}
	}
	cout << rec(0,-1,0)+rec(0,-1,1) << endl;
    return 0;
}
