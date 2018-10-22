#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
int N,K;
int a[5010];
int b[5010];
short dp[5010][5010];
vector<short> pre[5010];
vector<short> suf[5010];
int main(){
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		b[N-1-i]=a[i];
	}
	dp[0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<=K;j++){
			if(dp[i][j]){
				dp[i+1][j]=1;
				if(j+a[i]<=K)dp[i+1][j+a[i]]=1;
			}
		}
	}
	pre[0].pb(0);
	for(int i=0;i<N;i++){
		for(int j=0;j<=K;j++){
			if(dp[i+1][j])pre[i+1].pb(j);
		}
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<=K;j++){
			if(dp[i][j]){
				dp[i+1][j]=1;
				if(j+b[i]<=K)dp[i+1][j+b[i]]=1;
			}
		}
	}
	for(int i=0;i<N-1;i++){
		for(int j=0;j<=K;j++){
			if(dp[i+1][j])suf[N-2-i].pb(j);
		}
	}
	suf[N-1].pb(0);
	int ans = 0;
	for(int i=0;i<N;i++){
		/*for(int j=0;j<pre[i].size();j++){
			printf("%d ",pre[i][j]);
		}
		printf(": ");
		for(int j=0;j<suf[i].size();j++){
			printf("%d ",suf[i][j]);
		}
		printf("\n");*/
		for(int j=0;j<pre[i].size();j++){
			int t = K-a[i]-pre[i][j];
			int idx = lower_bound(all(suf[i]),t)-suf[i].begin();
			if(idx<(int)suf[i].size()&&pre[i][j]+suf[i][idx]<K){
				ans++;
				break;
			}
		}
	}
	cout << N-ans << endl;
	return 0;
}