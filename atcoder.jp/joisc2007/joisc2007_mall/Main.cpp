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
int w,h,a,b,ans=INF;
int map[1500][1500];
vector<P> v;
int search(int p,int q)
{
	if(p+b>h||q+a>w)return INF;
	vector<P>::iterator s,t,it;
	s=lower_bound(v.begin(),v.end(),mp(p,q));
	t=upper_bound(v.begin(),v.end(),mp(p+b-1,q+a-1));
	for(it=s;it!=t;it++)
	{
		int f=(*it).fi,se=(*it).sec;
		if(p<=f&&f<=p+b-1&&q<=se&&se<=q+a-1)return INF;
	}
	/*for(int i=0;i<v.size();i++)
	{
		int f=v[i].fi,se=v[i].sec;
		if(p<=f&&f<=p+b-1&&q<=se&&se<=q+a-1)return INF;
	}*/
	return map[p+b-1][q+a-1]-((q<1)?0:map[p+b-1][q-1])-((p<1)?0:map[p-1][q+a-1])+((p<1||q<1)?0:map[p-1][q-1]);
}
int main()
{
	cin >> w >> h;
	cin >> a >> b;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]==-1)
			{
				map[i][j]=0;
				v.pb(mp(i,j));
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<h;i++)
	{
		for(int j=1;j<w;j++)
		{
			map[i][j]+=map[i][j-1];
		}
	}
	for(int j=0;j<w;j++)
	{
		for(int i=1;i<h;i++)
		{
			map[i][j]+=map[i-1][j];
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			//cout << map[i][j] << ' ';
			//cout << i << ' ' << j << ' ' <<search(i,j) << endl;
			ans=min(ans,search(i,j));
		}
		//cout << endl;
	}
	cout << ans << endl;
	return 0;
}