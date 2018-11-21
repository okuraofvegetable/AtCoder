#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
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
ll mygcd(ll a,ll b){
	if(b==0ll)return a;
	return mygcd(b,a%b);
}
void solve(ll A,ll B,ll C,ll D){
	if(A<B){
		printf("No\n");
		return;
	}
	if(D<B){
		printf("No\n");
		return;
	}
	if(C>=B-1ll){
		printf("Yes\n");
		return;
	}
	ll s = A%B;
	ll d = D%B;
	ll k = mygcd(B,d);
	ll L = (C+1ll)%k, R =(B-1ll)%k;
	ll S = s%k;
	bool flag = true;
	if(L<=R){
		if(L<=S&&S<=R)flag = false;
	}else{
		if(S<=R||L<=S)flag = false;
	}
	if(s<=C&&k>=B-C&&flag){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return;
}
int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		solve(a,b,c,d);
	}
	return 0;
}