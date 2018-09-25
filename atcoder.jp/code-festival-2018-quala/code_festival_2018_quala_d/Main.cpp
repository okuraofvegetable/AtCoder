#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
ll MOD = 1000000007ll;
#define MAX_N 100100
struct BIT{
	ll bit[MAX_N+1];
	void add(int i,ll x){
		i++;
		while(x<0)x+=MOD;
		x%=MOD;
		while(i<=MAX_N){
			bit[i]+=x;
			bit[i]%=MOD;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		i++;
		ll res=0ll;
		while(i>0){
			res+=bit[i];
			res%=MOD;
			i-=i&-i;
		}
		return res;
	}
}bit;
ll p[100100];
int D,F,T,N;
int X[100100];
int l[100100],r[100100],d[100100];
int main(){
	cin >> D >> F >> T >> N;
	for(int i=1;i<=N;i++){
		cin >> X[i];
	}
	X[0]=0;
	N++;
	for(int i=0;i<N;i++){
		l[i] = upper_bound(X,X+N,X[i]+F-T)-X;
		r[i] = upper_bound(X,X+N,X[i]+F)-X;
		d[i] = l[i]-i-1;
		//cout << l[i] << ' ' << r[i] << ' ' << d[i] << endl;
	}
	p[0]=1ll;
	for(int i=1;i<=N;i++){
		p[i] = p[i-1]*2ll%MOD;
	}
	bit.add(0,1);
	bit.add(1,-1);
	for(int i=0;i<N;i++){
		ll x = bit.sum(i);
		//cout << x << endl;
		ll a = x*p[d[i]]%MOD;
		bit.add(l[i],a);
		bit.add(r[i],MOD-a);
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		if(D-X[i]<=F){
			ans += ((bit.sum(i)*p[d[i]])%MOD);
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}