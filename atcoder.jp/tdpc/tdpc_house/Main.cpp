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
#define INF 2000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)

typedef vector<ll> vec;
typedef vector<vec> mat;

const ll MOD = 1000000007;

mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++){
		for(int k=0;k<B.size();k++){
			for(int j=0;j<B[0].size();j++){
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
			}
		}
	}
	return C;
}

mat pow(mat A, ll n){
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++){
		B[i][i]=1ll;
	}
	while(n>0){
		if(n&1)B = mul(B,A);
		A = mul(A,A);
		n >>= 1;
	}
	return B;
}

// 1 1 2 3 5 8 ...
ll fib(ll x){
	mat A(2,vec(2));
	A[0][0]=1;A[0][1]=1;A[1][0]=1;A[1][1]=0;
	A = pow(A,x);
	return A[1][0];
}
int H,R;
int g[20][20];
ll dp[1<<16][16];
ll num[16][16];
int st;
ll rec(int S,int v){
	if(dp[S][v]!=-1)return dp[S][v];
	if(S==0)return dp[S][v]=0;
	if(S==(1<<st)&&v==st)return dp[S][v]=1;
	ll& res = dp[S][v];
	res = 0ll;
	for(int i=0;i<R;i++){
		if(i==v)continue;
		if(((S>>i)&1)&&g[i][v]==1){
			res += rec(S-(1<<v),i);
			res %= MOD;
		}
	}
	return res;
}
int main(){
	scanf("%d %d",&H,&R);
	for(int i=0;i<R;i++){
		for(int j=0;j<R;j++){
			scanf("%d",&g[i][j]);
		}
	}
	for(int i=0;i<R;i++){
		st=i;
		memset(dp,-1,sizeof(dp));
		for(int j=0;j<(1<<R);j++){
			if(!((j>>i)&1))continue;
			for(int k=0;k<R;k++){
				if((j>>k)&1){
					num[i][k]+=rec(j,k);
					num[i][k]%=MOD;
				}
			}
		}
	}
	mat A(R,vec(R));
	for(int i=0;i<R;i++){
		for(int j=0;j<R;j++){
			A[i][j]=num[i][j];
		}
	}
	A = pow(A,H);
	printf("%lld\n",A[0][0]);
	return 0;
}