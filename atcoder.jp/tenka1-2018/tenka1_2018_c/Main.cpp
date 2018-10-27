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
int N;
int a[100100];
int b[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	sort(a,a+N);
	ll ans = 0ll;
	ll res = 0ll;
	if(N==2){
		cout << abs(a[0]-a[1]) << endl;
		return 0;
	}
	if(N==3){
		swap(a[1],a[2]);
		chmax(ans,(ll)abs(a[0]-a[1])+(ll)abs(a[1]-a[2]));
		swap(a[1],a[2]);
		swap(a[0],a[1]);
		chmax(ans,(ll)abs(a[0]-a[1])+(ll)abs(a[1]-a[2]));
		cout << ans << endl;
		return 0;
	}
	int p = (N+1)/2;
	for(int i=0;i<(N+1)/2;i++){
		res-=a[i]*2ll;
	}
	for(int i=0;i<(N/2);i++){
		res+=a[N-1-i]*2ll;
	}
	if(N%2==1){
		chmax(ans,res+a[p-1]+a[p-2]);
	}else{
		chmax(ans,res-a[p]+a[p-1]);
	}
	if(N%2==1){
		res += a[p-1]*4ll;
		chmax(ans,res-a[p]-a[p-1]);
	}
	cout << ans << endl;
	return 0;
}