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
int N;
ll A[100100];
ll f(ll l,ll x){
	return ((l-1ll)/x+1ll)*x;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	ll l = 2, r = 2;
	for(int i=N-1;i>=0;i--){
		l = f(l,A[i]);
		if(l>r){
			cout << -1 << endl;
			return 0;
		}
		r = f(r+1ll,A[i])-1ll;
	}
	cout << l << ' ' << r << endl;
	return 0;
}