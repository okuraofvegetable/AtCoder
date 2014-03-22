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
int a[150],b[150];
bool used[150];
int main()
{
	int t,n,m;
	cin >> t;
	cin >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	cin >> m;
	for(int i=0;i<m;i++)cin >> b[i];
	for(int i=0;i<m;i++)
	{
		int cnt=0;
		for(cnt=0;cnt<n;cnt++)
		{
			if(b[i]>=a[cnt]&&b[i]-t<=a[cnt]&&!used[cnt])break;
		}
		if(cnt==n)
		{
			cout << "no" << endl;
			return 0;
		}
		used[cnt]=true;
	}
	cout << "yes" << endl;
	return 0;
}
