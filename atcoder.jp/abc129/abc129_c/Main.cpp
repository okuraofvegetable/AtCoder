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
ll MOD = 1000000007ll;
ll dp[100100];
bool broken[100100];
int N,M;
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a;
		cin >> a;
		broken[a]=true;
	}
	dp[0]=1ll;
	for(int i=1;i<=N;i++){
		if(broken[i])continue;
		if(i-1>=0)dp[i]=(dp[i]+dp[i-1])%MOD;
		if(i-2>=0)dp[i]=(dp[i]+dp[i-2])%MOD;
	}
	cout << dp[N] << endl;
	return 0;
}