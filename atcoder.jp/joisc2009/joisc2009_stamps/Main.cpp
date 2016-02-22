#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
string s;
string IO = "IO";
int dp[1000100][2];// 0 'I' 1 'O'
int pre[1000100][2];
int main(){
	scanf("%d",&N);
	cin >> s;
	for(int i=0;i<=N;i++)for(int j=0;j<2;j++)dp[i][j]=INF;
	dp[0][1]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			if(dp[i][j]==INF)continue;
			if(s[i]==IO[j]){
				if(dp[i+1][j^1]>dp[i][j]+1){ //replace
					dp[i+1][j^1]=dp[i][j]+1;
					pre[i+1][j^1]=j;
				}
				if(dp[i+1][j]>dp[i][j]+1){ // erase
					dp[i+1][j]=dp[i][j]+1;
					pre[i+1][j]=j;
				}
			}else{
				if(dp[i+1][j^1]>dp[i][j]){ 
					dp[i+1][j^1]=dp[i][j];
					pre[i+1][j^1]=j;
				}
				if(dp[i+1][j]>dp[i][j]+1){ // erase
					dp[i+1][j]=dp[i][j]+1;
					pre[i+1][j]=j;
				}
			}
		}
	}
	printf("%d\n",dp[N][0]);
	int len = N;
	int cur = 0;
	for(int i=N;i>0;i--){
		if(pre[i][cur]==cur){
			len--;
		}
		cur = pre[i][cur];
	}
	printf("%d\n",len);
	return 0;
}