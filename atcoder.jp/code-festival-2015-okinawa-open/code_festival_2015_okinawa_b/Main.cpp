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
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,X,Y;
int a[55],b[55];
int dp[55][55][10010];
int main(){
	for(int i=0;i<55;i++){
		for(int j=0;j<55;j++){
			for(int k=0;k<10010;k++)dp[i][j][k]=-INF;
		}
	}
	dp[0][0][0]=0;
	scanf("%d %d %d",&N,&X,&Y);
	for(int i=0;i<N;i++)scanf("%d %d",&a[i],&b[i]);
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=Y;k++){
				if(dp[i][j][k]==-INF)continue;
				//printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
				dp[i+1][j+1][min(Y,k+b[i])]=max(dp[i+1][j+1][min(Y,k+b[i])],dp[i][j][k]+a[i]+b[i]);
			}
		}
	}
	int ans = INF;
	for(int i=0;i<=N;i++){
		if(dp[N][i][Y]>=X+Y){
			ans = i;
			break;
		}
	}
	if(ans==INF)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
