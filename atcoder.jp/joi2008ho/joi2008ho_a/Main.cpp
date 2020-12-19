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
int n;
int p,ans=0;
vector<P> a;
int main()
{
	// while(1)
	{
		a.clear();
		cin >> n;
		// if(n==0)break;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin >> p;
			if(i%2==1)
			{
				if(sz(a)==0)
				{
					a.pb(P(p,1));
				}
				else if(a[sz(a)-1].fi!=p)
				{
					a.pb(P(p,1));
				}
				else
				{
					a[sz(a)-1].sec++;
				}
			}
			else
			{
				if(a[sz(a)-1].fi!=p)
				{
					int k=a[sz(a)-1].sec+1;
					a.pop_back();
					if(a.empty())
					{
						a.pb(P(p,k));
					}
					else
					{
						a[sz(a)-1].sec+=k;
					}
				}
				else
				{
					a[sz(a)-1].sec++;
				}
			}
		}
		for(int i=0;i<sz(a);i++)
		{
			if(a[i].fi==0)ans+=a[i].sec;
		}
		cout << ans << endl;
	}
	return 0;
}
