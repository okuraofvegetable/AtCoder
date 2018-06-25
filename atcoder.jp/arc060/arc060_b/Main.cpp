#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007ll
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
ll f(ll x,ll b){
	ll res = 0;
	while(x){
		res += x%b;
		x/=b;
	}
	return res;
}
ll n,s;
int main(){
	cin >> n >> s;
	if(n<s){
		cout << -1 << endl;
		return 0;
	}else if(n==s){
		cout << n+1 << endl;
		return 0;
	}
	for(ll i=2;i<400000;i++){
		if(s==f(n,i)){
			cout << i << endl;
			return 0;
		}
	}
	ll K = n-s;
	ll ans = -1;
	for(ll i=1;i*i<=K;i++){
		if(K%i!=0)continue;
		ll p = i;
		ll b = K/i+1ll;
		if(p<b&&s-p>=0&&s-p<b){
			ans = b;
		}
	}
	cout << ans << endl;
	return 0;
}