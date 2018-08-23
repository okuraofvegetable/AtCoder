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
ll N,X;
ll ans = 0;
void rec(ll a,ll b){
	//cout << a << ' ' << b << endl;
	if(a<b){
		rec(b,a);
		return;
	}
	if(a%b==0ll){
		ans += (2ll*(a/b)-1ll)*b;
		return;
	}
	ans += 2LL*(a/b)*b;
	rec(b,a%b);
}
int main(){
	cin >> N >> X;
	ans = N;
	rec(X,N-X);
	cout << ans << endl;
	return 0;
}