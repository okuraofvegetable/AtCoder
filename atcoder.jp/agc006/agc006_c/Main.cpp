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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int N;
ll x[100100];
int M;
ll K;
int A[100100];
vi mul(vi a,vi b){
	vi ret(a.size());
	for(int i=0;i<a.size();i++){
		ret[i] = b[a[i]];
	}
	return ret;
}
vi pow(vi a,ll y){
	vi ret;
	for(int i=0;i<a.size();i++){
		ret.pb(i);
	}
	while(y){
		if(y%2ll==1ll)ret = mul(ret,a);
		y /= 2ll;
		a = mul(a,a);
	}
	return ret;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> x[i];
	}
	vll y;
	for(int i=1;i<N;i++){
		y.pb(x[i]-x[i-1]);
	}
	cin >> M >> K;
	vi sig;
	for(int i=0;i<N-1;i++)sig.pb(i);
	for(int i=0;i<M;i++){
		cin >> A[i];
		A[i]--;
		swap(sig[A[i]],sig[A[i]-1]);	
	}
	// dump(sig);
	sig = pow(sig,K);
	// dump(sig);
	vll z(N-1);
	for(int i=0;i<N-1;i++){
		z[i] = y[sig[i]];
	}
	// dump(y);
	// dump(z);
	vll ans(N);
	ans[0] = x[0];
	for(int i=0;i<N-1;i++){
		ans[i+1] = ans[i]+z[i];
	}
	for(int i=0;i<N;i++){
		cout << ans[i] << endl;
	}
	return 0;
}
