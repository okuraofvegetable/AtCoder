#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
ll N,M;
string s,t;
ll gcd(ll a,ll b){
	if(b==0ll)return a;
	return gcd(b,a%b);
}
int main(){
	cin >> N >> M;
	cin >> s;
	cin >> t;
	ll ans = N/gcd(N,M)*M;
	ll a = ans/N, b = ans/M;
	ll g = a/gcd(a,b)*b;
	int c = 0,d = 0;
	for(int i=0;i<ans/g;i++){
		if(s[c]!=t[d]){
			cout << -1 << endl;
			return 0;
		}
		c += g/a;
		d += g/b;
	}
	cout << ans << endl;
	return 0;
}