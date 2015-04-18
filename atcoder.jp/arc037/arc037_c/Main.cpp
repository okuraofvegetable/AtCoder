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
int N,K;
ll a[30010],b[30010];
bool C(ll x)
{
	ll sum = 0ll;
	for(int i=0;i<N;i++)
	{
		ll f = x/a[i];
		int k = upper_bound(b,b+N,f)-b;
		sum += (ll)k;
	}
	return sum>=K;
}
int main()
{
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)scanf("%lld",&a[i]);
	for(int i=0;i<N;i++)scanf("%lld",&b[i]);
	sort(a,a+N);
	sort(b,b+N);
	ll l = 0ll,r = 2000000000000000000ll;
	while(r-l>1)
	{
		ll mid = (l+r)/2ll;
		if(C(mid))r=mid;
		else l=mid;
	}
	cout << r << endl;
	return 0;
}
