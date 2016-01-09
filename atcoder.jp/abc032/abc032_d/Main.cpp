#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,W;
int v[205],w[205];
ll dp[205][200100];
int type=0;
vector<P> vec;
int main(){
	scanf("%d %d",&N,&W);
	if(N<=30)type = 1;
	for(int i=0;i<N;i++){
		scanf("%d %d",&v[i],&w[i]);
		if(v[i]>1000&&!type)type=2;
		if(w[i]>1000&&!type)type=3;
	}
	if(type==1){
		ll ans = 0ll;
		int half = N/2,rem = N-half;
		for(int i=0;i<(1<<half);i++){
			P p = P(0,0);
			for(int j=0;j<half;j++){
				if((i>>j)&1){
					p.fi += (ll)w[j];
					p.sec += (ll)v[j];
				}
			}
			vec.pb(p);
		}
		sort(all(vec));
		int rsz = 1;
		for(int i=1;i<vec.size();i++){
			if(vec[rsz-1].sec<vec[i].sec){
				vec[rsz++]=vec[i];
			}
		}
		vec.resize(rsz);
		for(int i=0;i<(1<<rem);i++){
			P p = P(0,0);
			for(int j=0;j<rem;j++){
				if((i>>j)&1){
					p.fi += (ll)w[j+half];
					p.sec += (ll)v[j+half];
				}
			}
			if(p.fi>W)continue;
			int k = upper_bound(all(vec),P(W-p.fi+1,-1))-vec.begin();
			if(k==0)continue;
			k--;
			assert(p.fi+vec[k].fi<=W);
			ans=max(ans,vec[k].sec+p.sec);
		}
		printf("%lld\n",ans);
	}else if(type==2){
		for(int i=0;i<=N;i++)for(int j=0;j<200100;j++)dp[i][j]=-1;
		dp[0][0]=0ll;
		for(int i=0;i<N;i++){
			for(int j=0;j<200100;j++){
				//cout << dp[i][j] << ' ';
				if(dp[i][j]==-1)continue;
				dp[i+1][j+w[i]]=max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			}
			//cout << endl;
		}
		ll ans = 0ll;
		for(int i=0;i<=W;i++)ans = max(ans,dp[N][i]);
		printf("%lld\n",ans);
	}else{
		for(int i=0;i<=N;i++)for(int j=0;j<200100;j++)dp[i][j]=LLINF;
		dp[0][0]=0ll;
		for(int i=0;i<N;i++){
			for(int j=0;j<200100;j++){
				if(dp[i][j]==LLINF)continue;
				dp[i+1][j+v[i]]=min(dp[i+1][j+v[i]],dp[i][j]+w[i]);
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			}
		}
		int ans = 0ll;
		for(int i=0;i<200100;i++)if(dp[N][i]<=W)ans = max(ans,i);
		printf("%d\n",ans);
	}
	return 0;
}