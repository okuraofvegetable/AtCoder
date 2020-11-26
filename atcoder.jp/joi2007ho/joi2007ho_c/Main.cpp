#include <cstdio>
#include <cstring>
#include <cstdlib>
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
typedef complex<double> P;
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
#define X real()
#define Y imag()
#define EQ(a,b) (abs((a)-(b))<EPS)
short f[5001][5001];
int n;
int ans=0;
vector<P> v;
int main()
{
	//while(1)
	{
		ans=0;
		memset(f,0,sizeof(f));
		cin >> n;
		//if(n==0)break;
		for(int i=0;i<n;i++)
		{
			int p,q;
			cin >> p >> q;
			f[p][q]++;
			v.pb(P(p,q));
		}
		for(int i=0;i<v.size()-1;i++)
		{
			for(int j=i+1;j<v.size();j++)
			{
				P k=v[i]-v[j];
				P n=k*P(0,1);
				P c=v[i]+n;
				P d=v[j]+n;
				if(c.X-(int)c.X!=0||c.Y-(int)c.Y!=0||
				   d.X-(int)d.X!=0||d.Y-(int)d.Y!=0||
				   c.X<0||c.Y<0||c.X>5000||c.Y>5000||
				   d.X<0||d.Y<0||d.X>5000||d.Y>5000)
				{
					continue;
				}
				if(f[(int)c.X][(int)c.Y]&&f[(int)d.X][(int)d.Y])
				{
					P e=d-v[j];
					int sq=((int)k.X)*((int)e.Y)-((int)k.Y)*((int)e.X);
					if(sq<0)sq=-sq;
					ans=max(ans,sq);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
