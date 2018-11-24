#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
int N,K;
ll a[1010];
int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> a[i];
	}
	for(int i=1;i<=N;i++){
		a[i+1]+=a[i];
	}
	vector<ll> vec,nxt;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<=N;j++){
			vec.pb(a[j]-a[i]);
		}
	}
	ll ans = 0ll;
	for(int i=40;i>=0;i--){
		int cnt = 0;
		for(int j=0;j<vec.size();j++){
			if((vec[j]>>i)&1){
				cnt++;
				nxt.pb(vec[j]);
			}
		}
		if(cnt>=K){
			ans |= (1ll<<i);
			swap(vec,nxt);
		}
		nxt.clear();
	}
	cout << ans << endl;
	return 0;
}