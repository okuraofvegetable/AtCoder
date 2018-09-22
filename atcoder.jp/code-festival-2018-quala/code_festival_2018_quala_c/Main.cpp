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
ll MOD = 1000000007ll;
int N;
int K;
ll A[55];
int B[55];
ll dp[55][5002][2];
int f(ll x){
	int cnt = 0;
	while(x){
		x/=2ll;
		cnt++;
	}
	return cnt;
}
int main(){
	cin >> N >> K;
	int s = 0;
	for(int i=0;i<N;i++){
		cin >> A[i];
		B[i] = f(A[i]);
		s += B[i];
	}
	dp[0][0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<5000;j++){
			for(int k=0;k<=min(B[i],K);k++){
				if(B[i]-k==0){
					dp[i+1][j+B[i]-k][1]+=dp[i][j][0];
					dp[i+1][j+B[i]-k][1]+=dp[i][j][1];
				}else{
					dp[i+1][j+B[i]-k][1]+=dp[i][j][1];
					dp[i+1][j+B[i]-k][0]+=dp[i][j][0];
				}
				dp[i+1][j+B[i]-k][0]%=MOD;
				dp[i+1][j+B[i]-k][1]%=MOD;
			}
		}
	}
	ll ans = 0ll;
	if(s>K)ans = dp[N][s-K][0];
	for(int i=0;i<=min(s,K);i++){
		ans += dp[N][s-i][1];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}