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
#define LLINF 1000000000000000000ll
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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
template<class T>
void input(vector<T>& vec,int n){
	vec.resize(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
}
int N;
ll X;
ll x[300100];
ll rui[300100];
ll sum(int l,int r){
	if(l<=0)return rui[r];
	else return rui[r]-rui[l-1];
}
int main(){
	cin >> N >> X;
	for(int i=0;i<N;i++){
		cin >> x[i];
	}
	rui[0] = x[0];
	for(int i=1;i<N;i++){
		rui[i] = x[i]+rui[i-1];
	}
	ll ans = LLINF;
	for(int i=1;i<=N;i++){
		ll ret = X*(N+i);
		// cout << ret << ' ';
		for(int j=0;j<N;j+=i){
			ll c = j/i+1;
			ll k = max(5ll,2ll*c+1ll);
			ll ruis = sum(N-1-j-i+1,N-1-j);
			if((LLINF-ret)/k<=ruis){
				ret = LLINF;
				break;
			}
			ret += ruis*k;
		}
		// cout << ret << endl;
		ans = min(ans,ret);
	}
	cout << ans << endl;
	return 0;
}
