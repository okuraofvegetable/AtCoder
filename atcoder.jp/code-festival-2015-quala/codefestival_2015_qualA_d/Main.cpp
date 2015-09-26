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
int N,M;
ll X[100100];
bool check(ll time)
{
	ll b = 1;
	for(int i=0;i<M;i++)
	{
		if(X[i]-b>time)return false;
		if(b<X[i])b = max(X[i],max(b*2+time-X[i],X[i]+(time-(X[i]-b))/2))+1;
		else b=max(b-1,X[i]+time)+1;
		if(b>N)return true;
	}
	return false;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)scanf("%lld",&X[i]);
	ll l = -1,r = 2000000005;
	while(r-l>1)
	{
		ll mid = (l+r)/2;
		if(check(mid))r=mid;
		else l = mid;
	}
	printf("%lld\n",r);
	return 0;
}
