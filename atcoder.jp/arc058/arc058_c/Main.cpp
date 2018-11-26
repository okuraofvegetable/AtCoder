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
#define LLINF 100000000000000000ll
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
ModInt dp[42][1<<17];
bool ok[1<<17];
ModInt rui[42];
int N,X,Y,Z;
int main(){
	cin >> N >> X >> Y >> Z;
	int S = X+Y+Z;
	for(int i=0;i<(1<<S);i++){
		int a = ((i>>(X+Y+Z-1))&1);
		int b = ((i>>(Y+Z-1))&1);
		int c = ((i>>(Z-1))&1);
		if((a&b)&c)ok[i]=true;
	}
	dp[0][0]=ModInt(1ll);
	rui[0]=ModInt(1ll);
	int mask = (1<<S)-1;
	for(int i=1;i<=N;i++)rui[i]=rui[i-1]*ModInt(10ll);
	for(int i=0;i<N;i++){
		for(int j=0;j<(1<<S);j++){
			if(!ok[j]){
				for(int k=1;k<=10;k++){
					int nxt = (j<<k);
					nxt |= (1<<(k-1));
					dp[i+1][nxt&mask]+=dp[i][j];
				}
			}
		}
	}
	ModInt ans;
	for(int i=0;i<N;i++){
		for(int j=0;j<(1<<S);j++){
			if(ok[j]){
				ans += dp[i+1][j]*rui[N-1-i];
			}
		}
	}
	cout << ans << endl;
	return 0;
}