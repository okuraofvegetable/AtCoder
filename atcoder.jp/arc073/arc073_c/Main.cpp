#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
int N;
ll x[200100],y[200100];
P p[200100];
ll A[200100],B[200100];
ll ans = 0ll;
int main(){
	cin >> N;
	ll mi = LLINF,ma = -LLINF;
	ll a = -LLINF, b= LLINF;
	for(int i=0;i<N;i++){
		cin >> x[i] >> y[i];
		mi = min(mi,x[i]);
		mi = min(mi,y[i]);
		ma = max(ma,x[i]);
		ma = max(ma,y[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
		p[i].fi = x[i];
		p[i].sec= y[i];
		a = max(a,x[i]);
		b = min(b,y[i]);
	}
	ans = (a-mi)*(ma-b);
	sort(p,p+N);
	A[0]=B[0]=p[0].sec;
	for(int i=1;i<N;i++){
		A[i]=min(A[i-1],p[i].sec);
		B[i]=max(B[i-1],p[i].sec);
	}
	for(int i=0;i<N-1;i++){
		ll ret = (max(p[N-1].fi,B[i])-min(p[i+1].fi,A[i]))*(ma-mi);
		ans = min(ans,ret);
	}
	ans = min(ans,(p[N-1].fi-p[0].fi)*(ma-mi));
	ans = min(ans,(B[N-1]-A[N-1])*(ma-mi));
	cout << ans << endl;
	return 0;
}