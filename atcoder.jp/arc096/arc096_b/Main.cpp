#include<bits/stdc++.h>
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
ll C;
ll x[100100];
ll v[100100];
ll L[100100];
ll R[100100];
int main(){
	scanf("%d %lld",&N,&C);
	for(int i=0;i<N;i++){
		scanf("%lld %lld",&x[i],&v[i]);
	}
	ll sum = 0ll;
	for(int i=0;i<N;i++){
		if(i>0)L[i] = max(L[i],L[i-1]);
		sum += v[i];
		L[i] = max(L[i],sum-x[i]*2ll);
	}
	sum = 0ll;
	for(int i=N-1;i>=0;i--){
		if(i<N-1)R[i] = max(R[i],R[i+1]);
		sum += v[i];
		R[i] = max(R[i],sum-(C-x[i])*2ll);
	}
	ll ans = 0ll;
	sum = 0ll;
	for(int i=0;i<N;i++){
		sum += v[i];
		ans = max(ans,sum-x[i]+R[i+1]);
	}
	sum = 0ll;
	for(int i=N-1;i>=0;i--){
		sum += v[i];
		if(i>0)ans = max(ans,sum-(C-x[i])+L[i-1]);
		else ans = max(ans,sum-(C-x[i]));
	}
	cout << ans << endl;
	return 0;
}