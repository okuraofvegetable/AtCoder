#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
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
priority_queue<P,vector<P>,greater<P> > q;
int K,N;
ll A[100100],D[100100];
bool check(ll X){
	ll s = 0ll;
	for(int i=0;i<N;i++)if(A[i]<=X)s += ((X-A[i])/D[i])+1ll;
	return s>=(ll)K;
}
int main(){
	scanf("%d",&K);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld %lld",&A[i],&D[i]);
	ll l = 0ll, r = LLINF;
	while(r-l>1ll){
		ll mid = (l+r)/2ll;
		if(check(mid))r=mid;
		else l=mid;
	}
	ll rem = K;
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		ll c = (r-1ll>=A[i])?((r-1ll-A[i])/D[i]+1ll):0ll;
		c = min(rem,c);
		ans += A[i]*c+c*(c-1ll)/2ll*D[i];
		rem -= c;
	}
	ans += rem*r;
	printf("%lld\n",ans);
	return 0;
}