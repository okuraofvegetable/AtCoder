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
#define LLINF 1000000000000000
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
int K;
vector<ll> ans;
int main(){
	cin >> K;
	for(int i=1;i<9;i++)ans.pb(i);
	for(ll x=1;x<=10;x++){
		ll base = 1ll;
		for(int i=0;i<x;i++)base *= 10ll;
		for(ll i=x*base;i<=x*base*10ll;i+=base){
			ans.pb(i-1ll);
		}
	}
	for(ll i=1099999999999ll;i<=9999999999999ll;i+=100000000000ll){
		ans.pb(i);
	}
	for(ll i=10999999999999ll;i<=109999999999999ll;i+=1000000000000ll){
		ans.pb(i);
	}
	for(ll i=119999999999999ll;i<=1199999999999999ll;i+=10000000000000ll){
		ans.pb(i);
	}
	for(int i=0;i<K;i++)cout << ans[i] << endl;
	return 0;
}