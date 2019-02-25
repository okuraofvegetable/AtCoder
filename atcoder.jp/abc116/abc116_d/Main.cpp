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
int N,K;
P t[100100];
int num[100100];
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++)cin >> t[i].sec >> t[i].fi;
	sort(t,t+N);
	reverse(t,t+N);
	ll ret = 0ll;
	ll a = 0ll;
	for(int i=0;i<K;i++){
		if(num[t[i].sec]==0)a++;
		num[t[i].sec]++;
		ret += t[i].fi;
	}
	ll ans = ret+a*a;
	vector<P> rem;
	for(int i=K;i<N;i++){
		if(num[t[i].sec]==0){
			rem.pb(t[i]);
			num[t[i].sec]++;
		}
	}
	for(int i=0;i<rem.size();i++)num[rem[i].sec]--;
	int cnt = 0;
	for(int i=0;i<K;i++){
		int idx = K-1-i;
		if(num[t[idx].sec]==1)continue;
		if(cnt>=rem.size())break;
		num[t[idx].sec]--;
		ret -= t[idx].fi;
		num[rem[cnt].sec]++;
		ret += rem[cnt].fi;
		cnt++;
		a++;
		ans = max(ans,ret+a*a);
	}
	cout << ans << endl;
	return 0;
}