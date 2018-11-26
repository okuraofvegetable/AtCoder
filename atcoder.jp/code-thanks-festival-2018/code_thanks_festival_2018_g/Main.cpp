#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
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
int N,K,M;
int a[5010],b[5010];
int c[5010];
int used[5010];
vector<int> vec;
bool st[5010];
void dfs(int i){
	vec.pb(i);
	used[i]=true;
	if(!used[b[i]])dfs(b[i]);
}
int dp[5010][5010][2][2];
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> a[i];
		a[i]--;
	}
	for(int i=0;i<N;i++){
		cin >> c[i];
		c[i]--;
	}
	for(int i=0;i<N;i++){
		b[a[i]]=c[i];
	}
	st[0]=true;
	int res = 0;
	for(int i=0;i<N;i++){
		if(!used[i]){
			if(i!=b[i])dfs(i);
			else{
				res+=i;
				used[i]=true;
				K--;
			}
		}
		st[(int)vec.size()]=true;
	}
	M = N;
	N = vec.size();
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					dp[i][j][k][l]=-INF;
				}
			}
		}
	}
	dp[0][0][0][0]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=N;j++){
			if(st[i]){ //dp[i][j][0][0]
				chmax(dp[i+1][j+1][0][1],dp[i][j][0][0]+vec[i]);
				chmax(dp[i+1][j+1][1][0],dp[i][j][0][0]+b[vec[i]]);
			}else if(st[i+1]){
				chmax(dp[i+1][j+1][0][0],dp[i][j][0][0]+vec[i]);
				chmax(dp[i+1][j+1][0][0],dp[i][j][0][0]+b[vec[i]]);

				chmax(dp[i+1][j][0][0],dp[i][j][1][0]+vec[i]);
				chmax(dp[i+1][j+1][0][0],dp[i][j][1][0]+b[vec[i]]);

				chmax(dp[i+1][j+1][0][0],dp[i][j][0][1]+vec[i]);
				chmax(dp[i+1][j][0][0],dp[i][j][0][1]+b[vec[i]]);

				chmax(dp[i+1][j][0][0],dp[i][j][1][1]+vec[i]);
				chmax(dp[i+1][j][0][0],dp[i][j][1][1]+b[vec[i]]);
			}else{
				for(int k=0;k<2;k++){
					for(int l=0;l<2;l++){
						chmax(dp[i+1][j+(k==0)][0][l],dp[i][j][k][l]+vec[i]);
						chmax(dp[i+1][j+1][1][l],dp[i][j][k][l]+b[vec[i]]);
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i=K;i<=N;i++){
		chmax(ans,dp[N][i][0][0]);
	}
	cout << ans+res+M << endl;
	return 0;
}