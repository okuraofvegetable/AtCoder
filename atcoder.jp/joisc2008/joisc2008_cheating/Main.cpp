#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
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
#define EQ(a,b) (abs((a)-(b))<EPS)
vector<int> x,y;
int n,m;
bool C(int k)
{
	int ret=0;
	int pos=0;
	for(;;)
	{
		pos=upper_bound(x.begin(),x.end(),x[pos]+k)-x.begin();
		ret++;
		if(pos>=m)break;
	}
	pos=0;
	for(;;)
	{
		pos=upper_bound(y.begin(),y.end(),y[pos]+k)-y.begin();
		ret++;
		if(pos>=m)break;
	}
	return (ret<=n);
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		x.pb(a);y.pb(b);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	int l=0,r=INF;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid))r=mid;
		else l=mid;
	}
        if(C(l))r=l;
	cout << r << endl;
	return 0;
}
