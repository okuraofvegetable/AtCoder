#include<bits/stdc++.h>
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
ll s[100100];
vector<ll> dp[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> s[i];
	}
	ll ans = 0ll;
	for(int i=1;i<N-1;i++){
		dp[i].resize(N/i+5);
		fill(all(dp[i]),0);
	}
	for(int i=1;i<N-1;i++){
		for(int j=1;i*j<N-1;j++){
			dp[i][j]=dp[i][j-1]+s[N-1-j*i]+s[j*i];
			int a = N-1-i*j;
			if(a<=i)continue;
			if(a%i==0&&a/i<=j)continue;
			ans = max(ans,dp[i][j]);
			//cout << dp[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << ans << endl;
	return 0;
}