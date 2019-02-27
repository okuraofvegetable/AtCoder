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
int N,M;
int l[305],r[305],x[305];
ModInt dp[305][305][305];
bool ok[305][305][305];
int main(){
	init();
	dp[0][0][0]=ModInt(1ll);
	cin >> N >> M;
	memset(ok,true,sizeof(ok));
	for(int i=0;i<M;i++)cin >> l[i] >> r[i] >> x[i];
	for(int i=0;i<M;i++){
		if(x[i]==1){
			for(int j=l[i];j<r[i];j++){
				for(int k=0;k<r[i];k++){
					ok[r[i]][j][k]=false;
					ok[r[i]][k][j]=false;
					ok[j][r[i]][k]=false;
					ok[k][r[i]][j]=false;
					ok[j][k][r[i]]=false;
					ok[k][j][r[i]]=false;
				}
			}
		}else if(x[i]==2){
			for(int j=0;j<l[i];j++){
				for(int k=0;k<l[i];k++){
					ok[r[i]][j][k]=false;
					ok[r[i]][k][j]=false;
					ok[j][r[i]][k]=false;
					ok[k][r[i]][j]=false;
					ok[j][k][r[i]]=false;
					ok[k][j][r[i]]=false;
				}
			}
			for(int j=l[i];j<r[i];j++){
				for(int k=l[i];k<r[i];k++){
					ok[r[i]][j][k]=false;
					ok[r[i]][k][j]=false;
					ok[j][r[i]][k]=false;
					ok[k][r[i]][j]=false;
					ok[j][k][r[i]]=false;
					ok[k][j][r[i]]=false;
				}
			}
		}else{
			for(int j=0;j<l[i];j++){
				for(int k=0;k<r[i];k++){
					ok[r[i]][j][k]=false;
					ok[r[i]][k][j]=false;
					ok[j][r[i]][k]=false;
					ok[k][r[i]][j]=false;
					ok[j][k][r[i]]=false;
					ok[k][j][r[i]]=false;
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				int n = max(max(i,j),k)+1;
				if(ok[n][j][k])dp[n][j][k]+=dp[i][j][k];
				if(ok[i][n][k])dp[i][n][k]+=dp[i][j][k];
				if(ok[i][j][n])dp[i][j][n]+=dp[i][j][k];
			}
		}
	}
	ModInt ans;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(ok[N][i][j])ans+=dp[N][i][j];
			if(ok[i][N][j])ans+=dp[i][N][j];
			if(ok[i][j][N])ans+=dp[i][j][N];
		}
	}
	cout << ans << endl;
    return 0;
}
