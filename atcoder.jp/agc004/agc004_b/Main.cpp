#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
int N;
ll x;
ll a[2010];
ll b[2010][2010];
int main(){
	cin >> N >> x;
	for(int i=0;i<N;i++)cin >> a[i];
	ll ans = LLINF;
	for(int i=0;i<N;i++)b[i][0]=a[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			b[j][i+1]=min(b[j][i],a[(j+i+1)%N]);
		}
	}
	for(int i=0;i<N;i++){
		ll ret = x*i;
		for(int j=0;j<N;j++){
			ret += b[j][i];
		}
		ans = min(ans,ret);
	}
	cout << ans << endl;
	return 0;
}