#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
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
ll I,O,T,J,L,S,Z;
int main(){
	cin >> I >> O >> T >> J >> L >> S >> Z;
	ll ans = 0ll;
	ans += I/2ll*4ll;
	ans += O*2ll;
	ans += J/2ll*4ll;
	ans += L/2ll*4ll;
	ll ans2 = 0ll;
	if(I>0ll&&J>0ll&&L>0ll){
		ans2=6ll;
		I--;
		J--;
		L--;
		ans2 += I/2ll*4ll;
		ans2 += O*2ll;
		ans2 += J/2ll*4ll;
		ans2 += L/2ll*4ll;
	}
	cout << max(ans,ans2)/2ll << endl;
	return 0;
}