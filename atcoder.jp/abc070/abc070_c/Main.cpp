#include <bits/stdc++.h>
using namespace std;
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
ll mygcd(ll x,ll y){
	if(y==0)return x;
	else return mygcd(y,x%y);
}
int N;
ll T[105];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> T[i];
	}
	ll ans = 1ll;
	for(int i=0;i<N;i++){
		ans = ans/mygcd(ans,T[i])*T[i];
	}
	cout << ans << endl;
	return 0;
}
