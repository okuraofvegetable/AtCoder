#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
#define MOD 1000000007
int N;
int dp[200100];
int rui[200100];
int main(){
	cin >> N;
	vector<int> c(N);
	for(int i=0;i<N;i++)cin >> c[i];
	c.erase(unique(all(c)),c.end());
	N = c.size();
	dp[N]=1;
	for(int i=N-1;i>=0;i--){
		dp[i]=(rui[c[i]]+dp[i+1])%MOD;
		rui[c[i]]+=dp[i+1];
		rui[c[i]]%=MOD;
	}
	for(int i=0;i<N;i++){
		//cout << i << ' ' << dp[i] << endl;
	}
	cout << dp[0] << endl;
	return 0;
}