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
ModInt dp[65][2][2][2];
ll A,B;
#define N 64
int main(){
	init();
	cin >> A >> B;
	bitset<N> L(A);
	bitset<N> R(B);
	// cout << L << endl;
	// cout << R << endl;
	for(int i=0;i<32;i++){
		bool tmp;
		tmp = L[i];
		L[i] = L[N-1-i];
		L[N-1-i] = tmp;
		tmp = R[i];
		R[i] = R[N-1-i];
		R[N-1-i] = tmp;
	}	
	dp[0][1][1][0]=ModInt(1ll);
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					int nj,nk;
					// printf("i %d j %d k %d l %d\n",i,j,k,l);
					// cout << k << ' ' << R[i] << ' ' <<  (R[i]==false) << ' ' << (k&&R[i]==false) << endl;
					if(!(j&&L[i])){
						nj = (j&&(L[i]==false));
						nk = (k&&(R[i]==false));
						dp[i+1][nj][nk][l] += dp[i][j][k][l];
						//printf("type %d ni %d nj %d nk %d l %d\n",1,i+1,nj,nk,l);
					}
					if(!(k&&R[i]==false)){					
						nj = (j&&(L[i]));
						nk = (k&&(R[i]));
						dp[i+1][nj][nk][1] += dp[i][j][k][l];
						//printf("type %d ni %d nj %d nk %d l %d\n",2,i+1,nj,nk,l);
					}
					if((!(j&&L[i]==true))&&(!(k&&R[i]==false))&&l==1){
						nj = (j&&(L[i]==false));
						nk = (k&&(R[i]));
						dp[i+1][nj][nk][l] += dp[i][j][k][l];
						//printf("type %d ni %d nj %d nk %d l %d\n",3,i+1,nj,nk,l);
					}
					// printf("i %d j %d k %d l %d dp ",i,j,k,l);
					// cout << dp[i][j][k][l] << endl;
				}
			}
		}
	}
	ModInt ans;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ans += dp[N][i][j][1];
		}
	}
	cout << ans << endl;
	return 0;	
}

