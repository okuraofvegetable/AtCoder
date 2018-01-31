#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
int A,B;
int a[1010],b[1010];
int dp[1010][1010][2];
int rec(int s,int t,int k){
	if(dp[s][t][k]!=-1)return dp[s][t][k];
	int res = 0;
	if(k==0){
		if(s<A)res = max(res,rec(s+1,t,1)+a[s]);
		if(t<B)res = max(res,rec(s,t+1,1)+b[t]);
		return dp[s][t][k]=res;
	}else{
		res = INF;
		if(s<A)res = min(res,rec(s+1,t,0));
		if(t<B)res = min(res,rec(s,t+1,0));
		if(res==INF)res = 0;
		return dp[s][t][k]=res;
	}
}
int main(){
	scanf("%d %d",&A,&B);
	for(int i=0;i<A;i++)scanf("%d",&a[i]);
	for(int i=0;i<B;i++)scanf("%d",&b[i]);
	memset(dp,-1,sizeof(dp));
	cout << rec(0,0,0) << endl;
	return 0;
}