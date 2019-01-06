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
int c[100100][3];
int dp[100100][3];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			cin >> c[i][j];
		}
	}
	for(int i=0;i<3;i++)dp[0][i]=c[0][i];
	for(int i=1;i<N;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(j==k)continue;
				chmax(dp[i][j],dp[i-1][k]+c[i][j]);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<3;i++)chmax(ans,dp[N-1][i]);
	cout << ans << endl;
	return 0;
}