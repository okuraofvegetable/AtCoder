#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)

typedef vector<ll> vec;
typedef vector<vec> mat;

ll MOD;

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
void print(mat m){
	printf("\n");
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			printf("%lld ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
ll n,x,t,a,b,c;

int main(){
	scanf("%lld",&n);
	scanf("%lld %lld %lld %lld %lld",&x,&t,&a,&b,&c);
	MOD = c;
	mat A(2,vec(2));
	A[0][0]=a;A[0][1]=b;A[1][0]=0ll;A[1][1]=1ll;
	A = pow(A,t);
	//print(A);
	/*mat B(4,vec(4));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			B[i][j]=A[i][j];
		}
		B[2+i][i]=B[2+i][2+i]=1ll;
	}
	print(B);
	B = pow(B,n);
	print(B);*/
	ll ans = x;
	for(int i=1;i<n;i++){
		x = (A[0][0]*x+A[0][1])%MOD;
		ans += x;
	}
	/*ll aa = B[2][0]%MOD;
	ll bb = B[2][1]%MOD;
	ll ans = aa*x+bb;*/
	printf("%lld\n",ans);
	return 0;
}