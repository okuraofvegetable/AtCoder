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
int a[300100];
int main()
{
	int n,k,ans=0;
	cin >> n >> k;
	for(int i=0;i<n;i++)cin >> a[i];
	vector<int> vec;
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]<=a[i-1])vec.pb(cnt),cnt=1;
		else cnt++;
	}
	vec.pb(cnt);
	for(int i=0;i<vec.size();i++)ans+=max(0,vec[i]-k+1);
	cout << ans << endl;
	return 0;
}
