#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000ll
#define LLINF 2000000000000000000ll
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
ll A,B,K;
ll f(ll k){
	ll ret = 1ll;
	if(k>=A)ret *= k+1ll;
	else ret *= k;
	ll mul = K+1ll-k;
	if(K>=B){
		if(k<=K-B+1ll){
			mul++;
			if(LLINF/ret+1ll<mul)ret = LLINF;
			else ret *= mul;
		}else{
			if(LLINF/ret+1ll<mul)ret = LLINF;
			else ret *= mul;
		}
	}else{
		if(LLINF/ret+1ll<mul)ret = LLINF;
		ret *= mul;
	}
	return ret;
}
bool check(ll x){
	K = x;
	ll l=1ll,r=x;
	while(r-l>2ll){
		ll m = (l*2ll+r)/3ll;
		ll n = (l+r*2ll)/3ll;
		if(f(m)<f(n))l=m;
		else r=n;
	}
	ll mx = max(max(f(l),f(r)),f(l+1));
	return mx<(A*B);
}
ll solve(){
	ll l = 0ll,r = A*B;
	while(r-l>1ll){
		ll mid = (l+r)/2ll;
		if(check(mid))l=mid;
		else r = mid;
	}
	return l;
}
int Q;
int main(){
	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> A >> B;
		cout << solve() << endl;
	}
	return 0;
}