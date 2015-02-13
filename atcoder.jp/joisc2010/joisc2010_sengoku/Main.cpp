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
int L,N;
ll ans = 0ll;
vector<int> xy,yx;
vector<int> odd,even;
int x[100100],y[100100];
int main()
{
	scanf("%d %d",&L,&N);
	rep(i,N)scanf("%d %d",&x[i],&y[i]);
	rep(i,N)
	{
		xy.pb(x[i]+y[i]);
		yx.pb(y[i]-x[i]);
		if((y[i]-x[i])%2)odd.pb(y[i]-x[i]);
		else even.pb(y[i]-x[i]);
	}
	sort(all(xy));
	sort(all(yx));
	sort(all(odd));
	sort(all(even));
	xy.erase(unique(all(xy)),xy.end());
	yx.erase(unique(all(yx)),yx.end());
	odd.erase(unique(all(odd)),odd.end());
	even.erase(unique(all(even)),even.end());
	rep(i,xy.size())ans += L-abs(xy[i]-(L-1));
	rep(i,yx.size())ans += L-abs(yx[i]);
	rep(i,xy.size())
	{
		int beg,end,k;
		end = (xy[i]>L-1)?2*L-2-xy[i]:xy[i];
		beg = -end;
		//cout << beg << ' ' << end << endl;
		if(xy[i]%2)k = upper_bound(all(odd),end)-lower_bound(all(odd),beg);
		else k = upper_bound(all(even),end)-lower_bound(all(even),beg);
		ans -= k;
	}
	printf("%lld\n",ans);
	return 0;
}
 