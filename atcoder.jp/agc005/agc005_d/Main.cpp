#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
#define MOD 924844033ll // prime
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
int N,K;
ModInt dp[2010][2010][2];
ModInt ep[5010];
ModInt tmp[5010];
int main(){
	init();
	cin >> N >> K;
	ep[0] = ModInt(1ll);
	for(int i=0;i<min(2*K,N);i++){
		int s = i%K;
		int c = 0;
		while(s<N){
			c++;
			s += K;
		}
		c--;
		// cout << c << endl;
		for(int j=0;j<=c;j++){
			for(int k=0;k<=c;k++){
				for(int l=0;l<2;l++){
					dp[j][k][l]=ModInt(0ll);
				}
			}
		}
		dp[0][0][0] = ModInt(1ll);
		for(int j=0;j<c;j++){
			for(int k=0;k<c;k++){
				dp[j+1][k][0] += dp[j][k][0]+dp[j][k][1];
				dp[j+1][k+1][1] += dp[j][k][0];
			}
		}
		for(int j=1;j<=c;j++){
			for(int k=0;k<=c;k++){
				// cout << j << ' ' << k << ',' << dp[j][k][0] << ' ' << dp[j][k][1] << endl;
			}
		}
		for(int l=0;l<=N;l++){
			tmp[l] = ModInt(0ll);
		}
		for(int k=0;k<=c;k++){
			// cout << dp[c][k][0] << ' ' << dp[c][k][1] << endl;
			for(int l=0;l<=N;l++){
				tmp[k+l] += ep[l]*(dp[c][k][0]+dp[c][k][1]);
			}
		}
		for(int k=0;k<=N;k++){
			ep[k] = tmp[k];
		}
	}
	// for(int i=0;i<=N;i++){
	// 	cout << i << ' ' << ep[i] << endl;
	// }
	ModInt ans = 0;
	for(int i=0;i<=N;i++){
		ep[i] *= fac[N-i];
		if(i&1)ans -= ep[i];
		else ans += ep[i];
	}
	cout << ans << endl;
	return 0;
}
