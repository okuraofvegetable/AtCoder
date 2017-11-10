#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
#define MOD 1000000007
int N;
vector<int> D;
int dp[5][100100];
int main(){
	cin >> N;
	D.resize(N);
	for(int i=0;i<N;i++){
		cin >> D[i];
	}
	sort(all(D));
	for(int i=0;i<N;i++)dp[0][i]=i+1;
	for(int i=1;i<4;i++){
		for(int j=0;j<N;j++){
			int k = D[j]/2;
			int idx = upper_bound(all(D),k)-D.begin();
			if(idx>0)dp[i][j]=(dp[i-1][idx-1])%MOD;
		}
		for(int j=1;j<N;j++)dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
	}
	cout << dp[3][N-1] << endl;
	return 0;
}