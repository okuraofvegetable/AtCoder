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
struct SlideMax{
	deque<int> dq;
	void add(int x){
		while(!dq.empty()&&dq.back()<x)dq.pop_back();
		dq.push_back(x);
	}
	void erase(int x){
		if(dq.front()==x)dq.pop_front();
	}
	int get(){
		if(dq.empty())return -INF;
		return dq.front();
	}
}s;
int N,X;
int T[5010];
int L[5010];
int mx[5010];
int dp[5010][5010];
int main(){
	scanf("%d %d",&N,&X);
	for(int i=0;i<N;i++){
		scanf("%d",&T[i]);
	}
	for(int i=0;i<N;i++){
		L[i] = upper_bound(T,T+N,T[i]-X)-T;
	}
	for(int i=0;i<N;i++)dp[1][i]=X;
	for(int i=2;i<=N;i++){
		mx[0]=dp[i-1][0];
		for(int j=0;j<N;j++){
			int ret = 0;
			if(j>0)mx[j]=max(mx[j-1],dp[i-1][j]);
			if(L[j]>0)ret = mx[L[j]-1]+X;
			for(int k=(j==0?0:L[j-1]);k<L[j];k++)s.erase(dp[i-1][k]-T[k]);
			ret = max(ret,s.get()+T[j]);
			dp[i][j]=ret;
			s.add(dp[i-1][j]-T[j]);
		}
	}
	for(int i=1;i<=N;i++){
		int ans = 0;
		for(int j=0;j<N;j++)ans = max(ans,dp[i][j]);
		printf("%d\n",ans);
	}
	return 0;
}