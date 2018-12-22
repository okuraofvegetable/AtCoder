#include <bits/stdc++.h>
using namespace std;
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
ll N,P;
map<ll,int> m;
int main(){
	cin >> N >> P;
	ll Q = P;
	ll ans = 1ll;
	for(ll i=2ll;i*i<=Q;i++){
		if(P%i==0ll){
			ll k=0ll;
			while(P%i==0ll){
				P/=i;
				k++;
			}
			for(ll j=0ll;j<k/N;j++)ans *= i;
		}
	}
	if(N==1ll)ans *= P;
	cout << ans << endl;
	return 0;
}