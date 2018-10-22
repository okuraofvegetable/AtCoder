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
#define MAX_N 200100
struct BIT{
	ll bit[MAX_N+1];
	void add(int i,ll x){
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		i++;
		ll res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
	ll sum(int l,int r){ // [l,r]
		if(l==0)return sum(r);
		else return sum(r)-sum(l-1);
	}
}bit;
int N;
ll K;
ll a[200100];
int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> a[i];
		a[i]-=K;
	}
	vector<P> vec;
	vec.pb(P(0ll,0));
	for(int i=1;i<=N;i++){
		a[i]+=a[i-1];
		vec.pb(P(a[i],i));
	}
	sort(all(vec),greater<P>());
	ll ans = 0ll;
	for(int i=0;i<vec.size();i++){
		int idx = vec[i].sec;
		ll val = vec[i].fi;
		bit.add(idx,1ll);
		ans += bit.sum(idx+1,N);
	}
	cout << ans << endl;
	return 0;
}