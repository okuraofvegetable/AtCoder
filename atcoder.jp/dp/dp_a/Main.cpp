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
int N;
int h[100100];
int dp[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> h[i];
	for(int i=0;i<N;i++)dp[i]=INF;
	dp[0]=0;
	for(int i=1;i<N;i++){
		dp[i]=min(dp[i],dp[i-1]+abs(h[i]-h[i-1]));
		if(i>1)dp[i]=min(dp[i],dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout << dp[N-1] << endl;
	return 0;
}