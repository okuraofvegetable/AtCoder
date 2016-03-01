#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000.0
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SZ = 100100;
int N;
int dp[SZ];
vector<P> vec;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,r;
		scanf("%d %d",&x,&r);
		vec.pb(P(-(x+r),x-r));
	}
	sort(all(vec));
	for(int i=0;i<SZ;i++)dp[i]=INF;
	int idx = 0;
	while(idx<N){
		int f = vec[idx].fi;
		vector<P> upd;
		while(idx<N&&vec[idx].fi==f){
			int k = vec[idx].sec;
			int pos = lower_bound(dp,dp+N,k)-dp;
			upd.pb(P(pos,k));
			idx++;
		}
		for(int i=0;i<upd.size();i++){
			int pos = upd[i].fi,k=upd[i].sec;
			dp[pos]=min(dp[pos],k);
		}
	}
	int ans = lower_bound(dp,dp+SZ,INF)-dp;
	printf("%d\n",ans);
	return 0;
}