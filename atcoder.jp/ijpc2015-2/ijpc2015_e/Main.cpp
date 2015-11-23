#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
int N,T,K;
int A[100100];
int ma[17][100100],mi[17][100100];
int rm[100100],dp[100100];
bool check(int x){
	for(int i=0;i<N;i++){
		int cur = i;
		int pre = (i==0)?T:A[i-1];
		for(int j=16;j>=0;j--){
			if(cur+(1<<j)>N)continue;
			if(pre-x<=mi[j][cur]&&ma[j][cur]<=pre+x)cur += (1<<j);
		}
		if(cur>i)rm[i]=cur-1;
		else rm[i]=-1;
	}
	if(rm[0]==-1)return false;
	for(int i=0;i<=N;i++)dp[i]=INF;
	dp[0]=rm[0];
	for(int i=1;i<N;i++){
		if(rm[i]==-1)continue;
		int k = lower_bound(dp,dp+N,i-1)-dp;
		if(dp[k]==INF)break;
		if(dp[k+1]!=INF)dp[k+1]=max(dp[k+1],rm[i]);
		else if(dp[k]<rm[i])dp[k+1]=rm[i];
	}
	for(int i=0;i<=K;i++)if(dp[i]==N-1)return true;
	return false;
}
int main(){
	scanf("%d %d %d",&N,&T,&K);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		ma[0][i]=A[i];
		mi[0][i]=A[i];
	}
	for(int i=1;i<17;i++){
		for(int j=0;j<N;j++){
			if(j+(1<<i)>N)continue;
			ma[i][j]=max(ma[i-1][j],ma[i-1][j+(1<<(i-1))]);
			mi[i][j]=min(mi[i-1][j],mi[i-1][j+(1<<(i-1))]);
		}
	}
	int l = -1,r = INF;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))r = mid;
		else l = mid;
	}
	printf("%d\n",r);
	return 0;
}
