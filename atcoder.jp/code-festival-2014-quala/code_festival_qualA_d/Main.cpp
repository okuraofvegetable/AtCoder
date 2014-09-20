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
#define INF 10000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
bool can[12];
vector<int> dig;
ll ans=INF;
ll ansv;
ll s;
int r;
void dfs(int k,ll num,bool up,bool down,bool first)
{
	if(k==((int)dig.size()))
	{
		ll h = abs(s-num);
		if(ans>h)ansv=num;
		ans=min(ans,h);
		return;
	}
	if(up)
	{
		int pos;
		for(int i=0;i<10;i++)if(can[i])
		{
			pos=i;
			break;
		}
		num*=10ll;
		num+=(ll)pos;
		dfs(k+1,num,true,false,false);
		return;
	}
	if(down)
	{
		int pos;
		for(int i=9;i>=0;i--)if(can[i])
		{
			pos=i;
			break;
		}
		num*=10ll;
		num+=(ll)pos;
		dfs(k+1,num,false,true,false);
		return;
	}
	if(can[dig[k]])
	{
		num*=10ll;
		num+=(ll)dig[k];
		dfs(k+1,num,false,false,false);
	}
	else
	{
		if(first)
		{
			dfs(k+1,num,false,false,false);
		}
		ll tmp=num;
		for(int i=dig[k]-1;i>=0;i--)
		{
			if(can[i])
			{
				tmp*=10ll;
				tmp+=(ll)i;
				dfs(k+1,tmp,false,true,false);
				break;
			}
		}
		tmp=num;
		for(int i=dig[k]+1;i<10;i++)
		{
			if(can[i])
			{
				tmp*=10ll;
				tmp+=(ll)i;
				dfs(k+1,tmp,true,false,false);
				break;
			}
		}
	}
	return ;
}
int main()
{
	cin >> s >> r;
	ll tt=s;
	while(tt>0ll)
	{
		dig.pb(tt%10ll);
		tt/=10ll;
	}
	reverse(dig.begin(),dig.end());
	for(int i=1;i<(1<<10);i++)
	{
		if(__builtin_popcount(i)>r)continue;
		for(int j=0;j<10;j++)
		{
			can[j]=false;
			if((i>>j)&1)can[j]=true;
		}
		dfs(0,0ll,false,false,true);
	}
	//cout << ansv << endl;
	cout << ans << endl;
	return 0;
}
