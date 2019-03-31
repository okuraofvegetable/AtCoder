#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> P;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
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
int N,K;
int a[100100];
vector<int> g[100100];
P dp[100100];
void rec(int v){
	P ret = P(0,0);
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		rec(u);
		ret.fi += dp[u].fi;
		ret.sec = max(ret.sec,dp[u].sec+1);
	}
	if(a[v]!=0&&ret.sec==K-1){
		ret.fi++;
		ret.sec = -1;
	}
	dp[v]=ret;
	return;
}
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> a[i];
		a[i]--;
		if(i>0){
			g[a[i]].pb(i);
		}
	}
	int ans = 0;
	if(a[0]!=0)ans++;
	a[0]=0;
	rec(0);
	ans += dp[0].fi;
	cout << ans << endl;
	/*for(int i=0;i<N;i++){
		cout << i << ' ' << dp[i].fi << ' ' << dp[i].sec << endl;
	}*/
	return 0;
}