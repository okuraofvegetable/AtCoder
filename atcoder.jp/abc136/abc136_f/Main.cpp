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
ModInt pow(ModInt a,ll x){
	ModInt res = ModInt(1ll);
	while(x){
		if(x&1)res *= a;
		x >>= 1;
		a = a*a;
	}
	return res;
}
const int SIZE = 1<<18;
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
void dump(vector<int> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i] << ' ';
	}
	cout << endl;
}
struct segtree{
	vector<int> seg[SIZE*2];
	void init(){
		for(int i=SIZE-1;i>=0;i--){
			merge(all(seg[i*2+1]),all(seg[i*2+2]),back_inserter(seg[i]));
			// cout << i << " : ";
			// dump(seg[i]);
		}
	}
	int query(int a,int b,int k,int l,int r,int y){
		if(a<=l&&r<=b){
			return (lower_bound(all(seg[k]),y)-seg[k].begin());
		}else if(r<=a||b<=l){
			return 0;
		}else{
			int lch = query(a,b,k*2+1,l,(l+r)/2,y);
			int rch = query(a,b,k*2+2,(l+r)/2,r,y);
			return lch+rch;
		}
	}
	int query2(int a,int b,int k,int l,int r,int y){
		if(a<=l&&r<=b){
			return seg[k].size()-(lower_bound(all(seg[k]),y)-seg[k].begin());
		}else if(r<=a||b<=l){
			return 0;
		}else{
			int lch = query2(a,b,k*2+1,l,(l+r)/2,y);
			int rch = query2(a,b,k*2+2,(l+r)/2,r,y);
			return lch+rch;
		}
	}
}seg;
int N;
P p[200100];
vector<int> xz,yz;
int main(){
	// init();
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> p[i].fi >> p[i].sec;
		xz.pb(p[i].fi);
		yz.pb(p[i].sec);
	}
	sort(all(xz));
	sort(all(yz));
	xz.erase(unique(all(xz)),xz.end());
	yz.erase(unique(all(yz)),yz.end());
	for(int i=0;i<N;i++){
		p[i].fi=lower_bound(all(xz),p[i].fi)-xz.begin();
		p[i].sec=lower_bound(all(yz),p[i].sec)-yz.begin();
		// cout << p[i].fi << ' ' << p[i].sec << endl;
	}
	for(int i=0;i<N;i++){
		seg.seg[p[i].fi+SIZE-1].pb(p[i].sec);
	}
	seg.init();
	ModInt ans;
	ModInt one = ModInt(1ll);
	for(int i=0;i<N;i++){
		vector<int> v;
		v.pb(seg.query(0,p[i].fi,0,0,SIZE,p[i].sec));
		v.pb(seg.query(p[i].fi+1,N,0,0,SIZE,p[i].sec));	
		v.pb(seg.query2(0,p[i].fi,0,0,SIZE,p[i].sec));
		v.pb(seg.query2(p[i].fi+1,N,0,0,SIZE,p[i].sec));	
		// for(int i=0;i<4;i++){
		// 	cout << v[i] << ' ';
		// }
		// cout << endl;
		ModInt base = pow(ModInt(2ll),N-1);
		ans += base;
		// cout << base << endl;
		for(int j=0;j<(1<<4);j++){
			ModInt ret = one;
			for(int k=0;k<4;k++){
				if((j>>k)&1){
					ret *= pow(ModInt(2ll),v[k])-one;
				}
			}
			if((j&9)==9||(j&6)==6){
				ans += ret;
				// cout << ret << endl;
			}
		}
	}
	cout << ans << endl;
  return 0;
}

