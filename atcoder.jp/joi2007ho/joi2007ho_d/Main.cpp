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
#define EQ(a,b) (abs((a)-(b))<EPS)
vi win[5001];
int lose[5001];
bool visited[5001];
vi ans;
int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		win[a].pb(b);
		lose[b]++;
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(lose[j]==0&&!(visited[j]))
			{
				ans.pb(j);
				lose[j]=-1;
				if(!flag)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(lose[k]==0)
						{
							flag=1;
							break;
						}
					}
				}
				for(int k=0;k<win[j].size();k++)
				{
					lose[win[j][k]]--;
				}
				break;
			}
		}
	}
	for(int i=0;i<sz(ans);i++)
	{
		cout << ans[i] << endl;
	}
	cout << flag << endl;
	return 0;
}
