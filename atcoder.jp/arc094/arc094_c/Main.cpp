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
ll A[200100],B[200100];
int main(){
	scanf("%d",&N);
	bool flag = true;
	for(int i=0;i<N;i++){
		scanf("%lld %lld",&A[i],&B[i]);
		if(A[i]!=B[i])flag = false;
	}
	if(flag){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	vector<ll> vec;
	for(int i=0;i<N;i++){
		ans += A[i];
		if(A[i]>B[i])vec.pb(B[i]);
	}
	sort(all(vec));
	ans -= vec[0];
	cout << ans << endl;
	return 0;
}