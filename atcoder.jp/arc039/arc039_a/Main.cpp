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
int f(int a)
{
	int res = 1ll;
	for(int i=0;i<a-1;i++)res*=10;
	return res;
}
int main()
{
	int n,m;
	vector<int> v1,v2;
	scanf("%d %d",&n,&m);
	int n_ = n , m_ = m;
	while(n_>0)
	{
		v1.pb(n_%10);
		n_/=10;
	}
	while(m_>0)
	{
		v2.pb(m_%10);
		m_/=10;
	}
	reverse(all(v1));
	reverse(all(v2));
	int base = n-m;
	int ans = n-m;
	for(int i=0;i<v1.size();i++)
	{
		ans = max(ans,base+(9-v1[i])*f((int)v1.size()-i));
	}
	for(int i=0;i<v2.size();i++)
	{
		if(i==0)ans = max(ans,base+(v2[0]-1)*f((int)v2.size()-i));
		else ans = max(ans,base+v2[i]*f((int)v2.size()-i));
	}
	cout << ans << endl;
	return 0;
}

