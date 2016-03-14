#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int K;
string s;
int dp[1<<21][12];
int rui[3][1<<21];
int cnt(int c,int s,int L){
	int b = rui[c][s+L-1];
	if(s==0)return b;
	else return b-rui[c][s-1];
}
int rec(int s,int lev){
	if(dp[s][lev]!=-1)return dp[s][lev];
	if(lev==0)return dp[s][lev]=0;
	int L = 1<<(2*(lev-1));
	int res = 0;
	res += cnt(1,s,L)+cnt(2,s,L);
	res += cnt(0,s+L,L)+cnt(2,s+L,L);
	res += cnt(0,s+2*L,L)+cnt(1,s+2*L,L);
	res += rec(s+3*L,lev-1);
	return dp[s][lev]=res;
}
int main(){
	scanf("%d",&K);
	int N = 1<<(2*K);
	cin >> s;
	for(int i=0;i<N;i++){
		if(s[i]=='J')rui[0][i]++,rui[0][i+N]++;
		if(s[i]=='O')rui[1][i]++,rui[1][i+N]++;
		if(s[i]=='I')rui[2][i]++,rui[2][i+N]++;
	}
	for(int i=1;i<2*N;i++){
		for(int j=0;j<3;j++){
			rui[j][i]+=rui[j][i-1];
		}
	}
	memset(dp,-1,sizeof(dp));
	int ans = INF;
	for(int i=0;i<N;i++)ans = min(ans,rec(i,K));
	printf("%d\n",ans);
	return 0;
}