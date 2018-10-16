#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 20000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
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
int N,M;
int A[1010],B[1010];
ModInt dp[1010][1010];
ModInt DP[105][1010];
ModInt solve(vector<int> vec,int sum){
	int n = vec.size();
	cout << endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			DP[i][j]=ModInt(0ll);
		}
	}
	DP[0][0]=ModInt(1ll);
	for(int i=0;i<n;i++){
		for(int j=0;j<=sum;j++){
			for(int k=0;k<=j;k++){
				DP[i+1][j]+=DP[i][k]*dp[j-k][vec[i]];
			}
		}
	}
	return DP[n][sum];
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(int i=0;i<M;i++){
		scanf("%d",&B[i]);
	}
	for(int i=0;i<=1000;i++){
		dp[0][i]=ModInt(1ll);
		dp[i][1]=ModInt(1ll);
	}
	for(int i=1;i<=1000;i++){
		for(int j=2;j<=1000;j++){
			dp[i][j]=dp[i][j-1];
			if(i-j>=0)dp[i][j]+=dp[i-j][j];
		}
	}
	vector<int> u,v;
	for(int i=0;i<N;i++){
		if(!u.empty()&&u.back()==A[i]){
			v.back()++;
		}else{
			u.pb(A[i]);
			v.pb(1);
		}
	}
	ModInt a = solve(v,accumulate(B,B+M,0));
	u.clear();v.clear();
	for(int i=0;i<M;i++){
		if(!u.empty()&&u.back()==B[i]){
			v.back()++;
		}else{
			u.pb(B[i]);
			v.pb(1);
		}
	}
	ModInt b = solve(v,accumulate(A,A+N,0));
	cout << a*b << endl;
	return 0;
}