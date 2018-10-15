#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 20000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
string S;
int dp[55][55][55][2];
const int F = -500;
const int INVALID = -INF;
int rec(int l,int r,int k,int s){ // s: 0->max , 1->min
	if(dp[l][r][k][s]!=F)return dp[l][r][k][s];
	if((r-l+1)%2==0)return dp[l][r][k][s]=INVALID;
	if((r-l+1)==1){
		if(k>0){
			if(s==0)return dp[l][r][k][s]=9;
			else return dp[l][r][k][s]=0;
		}else{
			if(S[l]!='+'&&S[l]!='-')return dp[l][r][k][s]=(int)(S[l]-'0');
			else return dp[l][r][k][s]=INVALID;
		}
	}else{
		int res = (s==0)?-INF:INF;
		for(int i=l+1;i<r;i++){
			for(int j=0;j<k;j++){
				int a = rec(l,i-1,j,0);
				int b = rec(i,r-1,k-1-j,0);
				int c = rec(l,i-1,j,1);
				int d = rec(i,r-1,k-1-j,1);
				if(s==0){
					if(a!=INVALID&&b!=INVALID)res = max(res,a+b);
					if(a!=INVALID&&d!=INVALID)res = max(res,a-d);
				}else{
					if(c!=INVALID&&d!=INVALID)res = min(res,c+d);
					if(c!=INVALID&&b!=INVALID)res = min(res,c-b);
				}
			}
		}
		if(S[r]=='+'||S[r]=='-'){
			for(int i=l+1;i<r;i++){
				for(int j=0;j<=k;j++){
					int a = rec(l,i-1,j,0);
					int b = rec(i,r-1,k-j,0);
					int c = rec(l,i-1,j,1);
					int d = rec(i,r-1,k-j,1);
					if(s==0){
						if(S[r]=='+'){
							if(a!=INVALID&&b!=INVALID)res = max(res,a+b);
						}else{
							if(a!=INVALID&&d!=INVALID)res = max(res,a-d);
						}
					}else{
						if(S[r]=='+'){
							if(c!=INVALID&&d!=INVALID)res = min(res,c+d);
						}else{
							if(c!=INVALID&&b!=INVALID)res = min(res,c-b);
						}
					}
				}
			}
		}
		if(abs(res)==INF)return dp[l][r][k][s]=INVALID;
		else return dp[l][r][k][s]=res;
	}
}
int main(){
	int K;
	cin >> K;
	cin >> S;
	for(int i=0;i<53;i++){
		for(int j=0;j<53;j++){
			for(int k=0;k<53;k++){
				for(int l=0;l<2;l++){
					dp[i][j][k][l]=F;
				}
			}
		}
	}
	int ans = rec(0,S.size()-1,K,0);
	if(ans==INVALID)printf("NG\n");
	else{
		printf("OK\n");
		printf("%d\n",ans);
	}
	return 0;
}