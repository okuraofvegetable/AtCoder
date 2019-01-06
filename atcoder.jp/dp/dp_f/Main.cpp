#include <stdio.h>
#include <string.h>
char S[3010];
char T[3010];
int dp[3010][3010];
int prev[3010][3010];
int M = 10000;
char ans[3010];
int max(int a,int b){
	if(a<b)return b;
	else return a;
}
int main(){
	scanf("%s",S);
	scanf("%s",T);
	int A = strlen(S);
	int B = strlen(T);
	for(int i=1;i<=A;i++){
		for(int j=1;j<=B;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			if(dp[i][j-1]>dp[i-1][j])prev[i][j]=i*M+j-1;
			else prev[i][j]=(i-1)*M+j;
			if(S[i-1]==T[j-1]){
				if(dp[i][j]<dp[i-1][j-1]+1){
					dp[i][j]=dp[i-1][j-1]+1;
					prev[i][j]=(i-1)*M+j-1;
				}
			}
		}
	}
	int i=A,j=B;
	int idx = 3000;
	ans[idx--]=0;
	while(i!=0&&j!=0){
		int pi = prev[i][j]/M, pj = prev[i][j]%M;
		if(dp[pi][pj]<dp[i][j])ans[idx--]=S[pi];
		i=pi;
		j=pj;
	}
	printf("%s\n",ans+idx+1);
	return 0;
}