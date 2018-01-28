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
int N;
ll H[100100],S[100100];
ll rem[100100];
bool check(ll X){
	for(int i=0;i<N;i++){
		if(X<H[i])return false;
		rem[i]=(X-H[i])/S[i];
	}
	sort(rem,rem+N);
	for(int i=0;i<N;i++){
		if(i>rem[i])return false;
	}
	return true;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld %lld",&H[i],&S[i]);
	ll l = 0ll, r = LLINF;
	while(r-l>1ll){
		ll mid = (l+r)/2ll;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%lld\n",r);
	return 0;
}