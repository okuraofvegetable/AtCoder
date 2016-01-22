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
#define MOD 10000000
vector<int> x,y;
string s;
int W,H,N;
ll dp[2][1010];
inline int turnL(int x){
	if(x<=1)x+=2;
	else x=(x-1)%2;
	return x;
}
inline int turnR(int x){
	if(x<=1)x=3-x;
	else x-=2;
	return x;
}
int main(){
	scanf("%d %d",&W,&H);
	scanf("%d",&N);
	cin >> s;
	int cur;
	if(s[0]=='L')cur=0;
	else cur = 2;
	if(cur<=1)x.pb(cur);
	else y.pb(cur-2);
	for(int i=0;i<s.size();i++){
		if(s[i]=='L')cur=turnL(cur);
		else cur=turnR(cur);
		if(cur<=1)x.pb(cur);
		else y.pb(cur-2);
	}
	dp[0][0]=1ll;
	for(int i=0;i<x.size();i++){
		memset(dp[(i+1)%2],0,sizeof(dp[(i+1)%2]));
		if(x[i]==0){
			for(int j=1;j<=W;j++){
				dp[(i+1)%2][j]=(dp[(i+1)%2][j-1]+dp[i%2][j-1])%MOD;
			}
		}else{
			for(int j=W-1;j>=0;j--){
				dp[(i+1)%2][j]=(dp[(i+1)%2][j+1]+dp[i%2][j+1])%MOD;
			}
		}
	}
	ll X = dp[sz(x)%2][W];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1ll;
	for(int i=0;i<y.size();i++){
		memset(dp[(i+1)%2],0,sizeof(dp[(i+1)%2]));
		if(y[i]==0){
			for(int j=1;j<=H;j++){
				dp[(i+1)%2][j]=(dp[(i+1)%2][j-1]+dp[i%2][j-1])%MOD;
			}
		}else{
			for(int j=H-1;j>=0;j--){
				dp[(i+1)%2][j]=(dp[(i+1)%2][j+1]+dp[i%2][j+1])%MOD;
			}
		}
	}
	ll Y = dp[sz(y)%2][H];
	printf("%lld\n",X*Y%MOD);
	return 0;
}