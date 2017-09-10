#include<bits/stdc++.h>
using namespace std;
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
#define MOD 998244353ll // prime
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
const int SIZE = 1000;
ModInt inv[SIZE+10],fac[SIZE+10],facinv[SIZE+10];
ModInt pow2[SIZE+10];
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
	pow2[0]=ModInt(1ll);
	for(int i=1;i<=SIZE;i++)pow2[i]=pow2[i-1]*ModInt(2);
	return;
}
double add(double a,double b)
{
	if(abs(a+b)<eps*(abs(a)+abs(b)))return 0;
	return a+b;
}
struct P{
	double x,y;
	P() {}
	P(double x,double y) : x(x),y(y){}
	P operator + (P p){
		return P(add(x,p.x),add(y,p.y));
	}
	P operator - (P p){
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator * (double d){
		return P(x*d,y*d);
	}
	double dot(P p){
		return add(x*p.x,y*p.y);
	}
	double det(P p){
		return add(x*p.y,-y*p.x);
	}
	double norm(){
		return sqrt(x*x+y*y);
	}
	double norm2(){
		return x*x+y*y;
	}
	double dist2(P p){
		return sq(x-p.x)+sq(y-p.y);
	}
	P vert(){
		return P(y,-x);
	}
	void dump(){
		printf("%.12f %.12f\n",x,y);
		return;
	}
};
int N;
vector<P> ps;
int main(){
	init();
	scanf("%d",&N);
	ps.resize(N);
	for(int i=0;i<N;i++){
		scanf("%lf %lf",&ps[i].x,&ps[i].y);
	}
	ModInt ans = pow2[N];
	ans -= ModInt(1);
	ans -= ModInt(N);
	if(N>1)ans -= nCr(N,2);
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int cnt = 2;
			for(int k=0;k<N;k++){
				if(i==k)continue;
				if(j==k)continue;
				P ij = ps[j]-ps[i];
				P jk = ps[k]-ps[j];
				if(abs(ij.det(jk))<eps){
					if(k<j){
						cnt==0;
						break;
					}
					else cnt++;
				}
			}
			if(cnt>2){
				ModInt add = pow2[cnt];
				add -= nCr(cnt,2);
				add -= ModInt(cnt);
				add -= ModInt(1);
				ans -= add;
			}
		}
	}
	cout << ans << endl;
	return 0;
}