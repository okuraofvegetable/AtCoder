#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
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
ll solve(ll h,ll w){
	ll res;
	if(h%3ll==0ll)return 0ll;
	else res = w;
	for(ll i=1;i<w;i++){
		ll a = (w-i)*h;
		ll b = i*(h/2);
		ll c = i*(h-h/2);
		res = min(res,max(max(a,b),c)-min(min(a,b),c));
	}
	return res;
}
int main(){
	ll H,W;
	cin >> H >> W;
	cout << min(solve(H,W),solve(W,H)) << endl;
	return 0;
}