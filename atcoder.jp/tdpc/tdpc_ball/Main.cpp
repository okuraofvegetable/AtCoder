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
int N;
double dp[1<<16],pp;
double rec(int mask){
	if(dp[mask]!=-1.0)return dp[mask];
	double& res = dp[mask];
	if(mask==0)return res=0.0;
	res = INF;
	for(int i=0;i<16;i++){
		double p = 0.0,E = 1.0;
		if(i>0 && (mask>>(i-1))&1){
			p += pp;
			E += pp*rec(mask-(1<<(i-1)));
		}
		if((mask>>i)&1){
			p += pp;
			E += pp*rec(mask-(1<<i));
		}
		if((mask>>(i+1))&1){
			p += pp;
			E += pp*rec(mask-(1<<(i+1)));
		}
		if(p==0.0)continue;
		res = min(res,E/p);
	}
	return res;
}
int main(){
	scanf("%d",&N);
	int mask = 0;
	pp = 1.0/3.0;
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		mask |= (1<<x);
	}
	for(int i=0;i<(1<<16);i++)dp[i]=-1.0;
	printf("%.12f\n",rec(mask));
	return 0;
}