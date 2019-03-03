#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
int K = 0;
ll pt[20];
int GETA = 9;
ll comb[2][20];
ll ans = 0ll;
void dfs(int d,ll rem,ll x){
	if(K-1-d==d){
		if(rem==0ll){
			ans += x*10ll;
		}
		return;
	}
	if(K-1-d<d){
		if(rem==0ll){
			//cout << d <<  ' ' << rem << ' ' << x << endl;
			ans += x;
		}
		return;
	}
	ll pl = LLINF; int p = -10;
	ll mi = -LLINF; int m = -10;
	for(int i=-9;i<=9;i++){
		ll tmp = rem+(ll)i*(pt[K-1-d]-pt[d]);
		if(tmp>0ll){
			if(pl>tmp){
				pl = tmp;
				p = i;
			}
		}else{
			if(mi<tmp){
				mi = tmp;
				m = i;
			}
		}
	}
	if(p!=-10)dfs(d+1,pl,x*comb[!d][p+GETA]);
	if(m!=-10)dfs(d+1,mi,x*comb[!d][m+GETA]);
}
int dig(ll X){
	int res = 0;
	while(X>0ll){
		X /= 10ll;
		res++;
	}
	return res;
}
int main(){
	ll D;
	cin >> D;
	pt[0]=1ll;
	for(int i=1;i<=18;i++){
		pt[i]=pt[i-1]*10ll;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			comb[0][i-j+GETA]++;
		}
	}
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			comb[1][i-j+GETA]++;
		}
	}
	int DIG = dig(D);
	for(int i=DIG;i<=DIG*2;i++){
		K = i;
		dfs(0,D,1ll);
	}
	cout << ans << endl;
	return 0;
}