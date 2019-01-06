#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
double p[3010];
double dp[3010][3010];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)cin >> p[i];
	dp[0][0]=1.0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=i+1;j++){
			dp[i+1][j]+=dp[i][j]*(1.0-p[i]);
			if(j>0)dp[i+1][j]+=dp[i][j-1]*p[i];
		}
	}
	double ans = 0.0;
	for(int i=0;i<=N;i++){
		if(i>N-i)ans += dp[N][i];
	}
	printf("%.12f\n",ans);
	return 0;
}