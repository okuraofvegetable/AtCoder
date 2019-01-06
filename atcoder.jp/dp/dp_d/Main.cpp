#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000100
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
int N,W;
int w[105];
ll v[105];
ll dp[105][100100];
int main(){
	cin >> N >> W;
	for(int i=0;i<N;i++){
		cin >> w[i] >> v[i];
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=W;j++){
			dp[i][j]=-INF;
		}
	}
	dp[0][0]=0ll;
	for(int i=0;i<N;i++){
		for(int j=0;j<=W;j++){
			chmax(dp[i+1][j],dp[i][j]);
			if(j>=w[i])chmax(dp[i+1][j],dp[i][j-w[i]]+v[i]);
		}
	}
	ll ans = 0ll;
	for(int i=0;i<=W;i++)chmax(ans,dp[N][i]);
	cout << ans << endl;
	return 0;
}