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
ll MOD = 1000000007ll;
int N;
int T[100100];
map<int,ll> m;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&T[i]);
		m[T[i]]++;
	}
	sort(T,T+N);
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		ans += T[i];
		T[i+1]+=T[i];
	}
	cout << ans << endl;
	ans = 1ll;
	map<int,ll>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		int c = it->sec;
		for(int i=2;i<=c;i++)ans = (ans*(ll)i)%MOD;
	}
	cout << ans << endl;
	return 0;
}