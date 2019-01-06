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

ll MOD = 1000000007ll;

mat mul(mat &A,mat &B)
{
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
	{
		for(int k=0;k<B.size();k++)
		{
			for(int j=0;j<B[0].size();j++)
			{
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
			}
		}
	}
	return C;
}

mat pow(mat A, ll n)
{
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++)
	{
		B[i][i]=1ll;
	}
	while(n>0)
	{
		if(n&1)B = mul(B,A);
		A = mul(A,A);
		n >>= 1;
	}
	return B;
}

// 1 1 2 3 5 8 ...
ll fib(ll x)
{
	mat A(2,vec(2));
	A[0][0]=1;A[0][1]=1;A[1][0]=1;A[1][1]=0;
	A = pow(A,x);
	return A[1][0];
}
int N;
ll K;
int main(){
	cin >> N >> K;
	mat G;
	G.resize(N);
	for(int i=0;i<N;i++)G[i].resize(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> G[i][j];
		}
	}
	mat R = pow(G,K);
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			ans += R[i][j];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}