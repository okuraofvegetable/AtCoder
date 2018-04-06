#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef multiset<int>::iterator msi;
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
int A;
int x[55];
ll dp[55][55][2550];
int main(){
	cin >> N;
	cin >> A;
	for(int i=0;i<N;i++){
		cin >> x[i];
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=50*(i+1);k++){
				dp[i+1][j][k]+=dp[i][j][k];
				dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
				//cout << dp[i][j][k] << ' ';
			}
		}
	}
	ll ans = 0ll;
	for(int i=1;i<=N;i++){
		ans += dp[N][i][i*A];
	}
	cout << ans << endl;
	return 0;
}