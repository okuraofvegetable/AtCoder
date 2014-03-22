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
int d[55][55];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> d[i][j];
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]+=d[i][j-1];
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[j][i]+=d[j-1][i];
		}
	}
	int q;
	cin >> q;
	for(int t=0;t<q;t++)
	{
		int p;
		cin >> p;
		int ans=0;
		for(int s=1;s<=n;s++)
		{
			int w=min(p/s,n);
			if(w==0)continue;
			for(int i=1;i<=n-s+1;i++)
			{
				for(int j=1;j<=n-w+1;j++)
				{
					ans=max(ans,d[i+s-1][j+w-1]-d[i+s-1][j-1]-d[i-1][j+w-1]+d[i-1][j-1]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}