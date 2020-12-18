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
int r[101],b[101];
int memo[101];
P h[101];
int ans;
int rec(int s)
{
	if(memo[s]>0)return memo[s];
	if(r[s]==0&&b[s]==0)
	{
		memo[s]=h[s].fi+h[s].sec;
		return memo[s];
	}
	else if(r[s]==0&&b[s]!=0)
	{
		memo[s]=rec(b[s])/__gcd(h[s].fi,rec(b[s]))*(h[s].fi+h[s].sec);
		return memo[s];
	}
	else if(r[s]!=0&&b[s]==0)
	{
		memo[s]=rec(r[s])/__gcd(h[s].sec,rec(r[s]))*(h[s].fi+h[s].sec);
		return memo[s];
	}
	else
	{
		int tp,tq;
		tp=h[s].fi;tq=h[s].sec;
		int k=rec(b[s])/__gcd(rec(b[s]),tp);
		tp*=k;tq*=k;
		k=rec(r[s])/__gcd(rec(r[s]),tq);
		tp*=k;
		tq*=k;
		memo[s]=tp+tq;
		return memo[s];
	}
}
int main()
{
	//while(1)
	{
		memset(r,0,sizeof(r));
		memset(b,0,sizeof(b));
		memset(memo,0,sizeof(memo));
		ans=0;
		for(int i=0;i<101;i++)
		{
			h[i].fi=0;
			h[i].sec=0;
		}
		cin >> n;
		//if(n==0)break;
		for(int i=1;i<=n;i++)
		{
			int p,q,re,bl;
			cin >> p >> q >> re >> bl;
			int k=__gcd(p,q);
			p/=k;
			q/=k;
			h[i]=mp(p,q);
			r[i]=re;
			b[i]=bl;
		}
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,rec(i));
		}
		cout << ans << endl;
	}
	return 0;
}
