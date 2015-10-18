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
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
ll A[100100];
/*ll imos[100100];
bool check(ll x)
{
	memset(imos,0,sizeof(imos));
	ll cnt=0;
	ll l=A[0];
	for(int i=0;i<N;i++)
	{
		if(cnt<A[i])
		{
			l+=A[i]-cnt;
			if(i>0)imos[i-1]+=A[i]-cnt;
			cnt=A[i];
		}
		l++;
	}
	for(int i=N-1;i>0;i--)imos[i-1]+=imos[i];
	ll add = 0;
	for(int i=0;i<N;i++)add=max(add,A[i]-imos[i]);
	l+=add;
	if(l<=x)return true;
	else return false;
}*/
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]);
	/*ll l=-1,r=LLINF;
	while(r-l>1)
	{
		ll mid = (l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%lld\n",r);*/
	sort(A,A+N,greater<ll>());
	ll ans=A[0];
	for(int i=0;i<N;i++)
	{
		if(i>0&&A[i]>A[i-1])ans+=A[i]-A[i-1];
		ans++;
		ans+=A[i];
	}
	printf("%lld\n",ans);
	return 0;
}
