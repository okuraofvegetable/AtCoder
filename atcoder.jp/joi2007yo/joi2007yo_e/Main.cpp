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
typedef pair<P,P> Q;
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
int t[301];
vector<Q> re;
int main()
{
	//while(1)
	{
		re.clear();
	for(int i=0;i<301;i++)
	{
		t[i]=2;
	}
	int a,b,c;
	cin >> a >> b >> c;
	//if(a==0&&b==0&&c==0)break;
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		Q p;
		cin >> p.fi.fi >> p.fi.sec >> p.sec.fi >> p.sec.sec;
		if(p.sec.sec==1)
		{
			t[p.fi.fi]=1;
			t[p.fi.sec]=1;
			t[p.sec.fi]=1;
		}
		else
		{
			re.pb(p);
		}
	}
	for(int i=0;i<sz(re);i++)
	{
		if(t[re[i].fi.fi]==1&&t[re[i].fi.sec]==1&&t[re[i].sec.fi]!=1)
		{
			t[re[i].sec.fi]=0;
		}
		else if(t[re[i].fi.fi]!=1&&t[re[i].fi.sec]==1&&t[re[i].sec.fi]==1)
		{
			t[re[i].fi.fi]=0;
		}
		else if(t[re[i].fi.fi]==1&&t[re[i].fi.sec]!=1&&t[re[i].sec.fi]==1)
		{
			t[re[i].fi.sec]=0;
		}
		else
		{}
	}
	for(int i=1;i<=(a+b+c);i++)
	{
		cout << t[i] << endl;
	}
	}
	return 0;
}
