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
int a[100100];
vector<int> vec;
int n;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			cnt++;
			continue;
		}
		else
		{
			vec.pb(cnt);
			cnt=1;
		}
	}
	vec.pb(cnt);
	int ans=1;
	//for(int i=0;i<vec.size();i++)cout << vec[i] << endl;
	if(vec.size()<3)
	{
		ans=0;
		for(int i=0;i<vec.size();i++)
		{
			ans+=vec[i];
		}
	}
	for(int i=2;i<vec.size();i++)
	{
		ans=max(ans,vec[i-2]+vec[i-1]+vec[i]);
	}
	cout << ans << endl;
	return 0;
}
