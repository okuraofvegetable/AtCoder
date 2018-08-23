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
ll A[200100];
ll sum[200100];
ll x[200100];
int check(int l,int r){
	return (x[r+1]^x[l]) == sum[r+1]-sum[l];
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<N;i++){
		sum[i+1] = sum[i]+A[i];
		x[i+1] = x[i]^A[i];
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		int l = i, r = N;
		while(r-l>1){
			int mid = (l+r)/2;
			if(check(i,mid))l=mid;
			else r=mid;
		}
		ans += (ll)(l-i+1);
	}
	cout << ans << endl;
	return 0;
}