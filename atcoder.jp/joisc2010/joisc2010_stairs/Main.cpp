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
#define MOD 1234567
const int SIZE = 1<<19;
struct segtree
{
	int seg[SIZE*2];
	void update(int k,int x)
	{
		k += SIZE-1;
		seg[k]=x;
		while(k)
		{
			k = (k-1)/2;
			seg[k]=(seg[k*2+1]+seg[k*2+2])%MOD;
		}
	}
	int query(int a,int b,int k,int l,int r)
	{
		if(r<=a||b<=l)return 0;
		if(a<=l&&r<=b)return seg[k];
		return (query(a,b,k*2+1,l,(l+r)/2)+query(a,b,k*2+2,(l+r)/2,r))%MOD;
	}
}seg;
int dp[500100];
int h[500100];
int N,P;
int main()
{
	scanf("%d %d",&N,&P);
	for(int i=1;i<=N;i++)scanf("%d",&h[i]);
	rep(i,N+1)h[i+1]+=h[i];
	dp[0]=1;
	seg.update(0,1);
	for(int i=1;i<=N;i++)
	{
		int k = lower_bound(h,h+N+1,h[i]-P)-h;
		if(k<i)dp[i]=seg.query(k,i,0,0,SIZE);
		seg.update(i,dp[i]);
	}
	printf("%d\n",dp[N]);
	return 0;
}
