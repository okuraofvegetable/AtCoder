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
ll pow(ll x,ll a,ll mod){
	if(a==0ll)return 1ll;
	ll res=pow(x*x%mod,a/2ll,mod);
	if(a&1)res=res*x%mod;
	return res;
}
int p;
int a[3010];
int rag[3010][3010];
int inv[3010];
int b[3010];
vi pol[3010];
vi mul(vi v,int k){
	// mul (x-k)
	int n = v.size();
	vi res(n+1);
	for(int i=0;i<n;i++){
		res[i] = v[i];
	}
	for(int i=0;i<n;i++){
		res[i+1] += v[i]*(-k);
		res[i+1] %= p;
		res[i+1] = (res[i+1]+p)%p;
	}
	return res;
}
vi div(vi v,int k){
	int n = v.size();
	vi res(n-1);
	for(int i=0;i<n-1;i++){
		res[i] = v[i];
		v[i+1] -= res[i]*(-k);
		v[i+1] %= p;
		v[i+1] = (v[i+1]+p)%p;
	}
	assert(v[n-1]%p==0);
	return res;
}
vector<int> poly;
int main(){
	cin >> p;
	for(int i=0;i<p;i++){
		cin >> a[i];
	}
	for(int i=1;i<p;i++){
		inv[i] = pow(i,p-2,p);
	}
	vi vec;
	vec.pb(1);
	for(int i=0;i<p;i++){
		vec = mul(vec,i);
	}
	for(int i=0;i<p;i++){
		pol[i] = div(vec,i);
	}
	for(int i=0;i<p;i++){
		b[i] = 1;
		for(int j=0;j<p;j++){
			if(i!=j)b[i] = (b[i]*inv[(i-j+p)%p])%p;
		}
	}
	vi ans(p);
	for(int i=0;i<p;i++){
		if(a[i]){
			for(int j=0;j<p;j++){
				ans[j] += pol[i][j]*b[i];
				ans[j] %= p;
				ans[j] += p;
				ans[j] %= p;
			}
		}
	}
	for(int i=0;i<p;i++){
		cout << ans[p-1-i];
		if(i+1<p)cout << ' ';
		else cout << endl;
	}
	return 0;
}
