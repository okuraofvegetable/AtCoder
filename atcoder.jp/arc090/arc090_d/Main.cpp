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
int f(ll x){
	int res = 0;
	while(x){
		x/=10ll;
		res++;
	}
	return res;
}
ll num(int x){
	x--;
	ll res = 9ll;
	for(int i=0;i<x;i++){
		res=(res*10ll)%MOD;
	}
	return res;
}
int S;
int d[3000000];
int main(){
	cin >> S;
	ll ans = 0ll;
	for(int i=1;i*i<=S;i++){
		if(S%i!=0)continue;
		ll add = num(i)-S/i+1ll;
		if(i>=9||add>0){
			ans += add;
			ans %= MOD;
		}
		if(i==S/i)continue;
		add = num(S/i)-i+1ll,0ll;
		if(i>=9||add>0){
			ans += add;
			ans %= MOD;
		}
	}
	int sum = 0;
	ll r = 1ll;
	for(int i=1;i<1000000;i++){
		while(sum<S){
			sum += f(r++);
		}
		if(sum==S&&f(i)<f(r-1))ans++;
		sum -= f(i);
	}
	ans %= MOD;
	int L = 9000000;
	for(int i=1;i<=S/7;i++){
		if(S%i==0)continue;
		int a = i-(S%i);
		if(S/i==7&&a>L)continue;
		ans++;
	}
	ans %= MOD;
	cout << ans << endl;
	return 0;
}