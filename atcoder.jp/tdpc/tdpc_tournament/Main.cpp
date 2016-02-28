#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int K;
int R[1050];
double dp[11][1050];
int pos[11][1050];
P seg[1<<12];
void rec(int k,int l,int r){
	seg[k]=P(l,r);
	if(r-l==1)return;
	rec(k*2+1,l,(l+r)/2);
	rec(k*2+2,(l+r)/2,r);
}
double win(int a,int b){
	double exp = ((double)(R[b]-R[a]))/400.0;
	double d = pow(10,exp)+1.0;
	return 1.0/d;
}
int main(){
	scanf("%d",&K);
	for(int i=0;i<(1<<K);i++){
		dp[0][i]=1.0;
		scanf("%d",&R[i]);
	}
	rec(0,0,1<<K);
	for(int i=0;i<(1<<K);i++){
		int k = i+(1<<K)-1;
		pos[0][i]=k;
		for(int j=1;j<=K;j++){
			k = (k-1)/2;
			pos[j][i]=k;
		}
	}
	for(int i=1;i<=K;i++){
		for(int j=0;j<(1<<K);j++){
			P range;
			if(pos[i-1][j]%2==1)range = seg[pos[i-1][j]+1];
			else range = seg[pos[i-1][j]-1];
			for(int k=range.fi;k<range.sec;k++){
				dp[i][j]+=dp[i-1][j]*dp[i-1][k]*win(j,k);
			}
		}
	}
	for(int i=0;i<(1<<K);i++)printf("%.12f\n",dp[K][i]);
	return 0;
}