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
int n;
bool k[367];
int p[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
int serch(int t)
{
	while(k[t])
	{
		t++;
	}
	if(t>366)return 0;
	return t;
}
int main()
{
	for(int i=1;i<=366;i++)
	{
		if(i%7==0||i%7==1)k[i]=true;
	}
	cin >> n;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d/%d",&a,&b);
		if(!k[p[a]+b])k[p[a]+b]=true;
		else vec.pb(p[a]+b);
	}
	SORT(vec);
	for(int i=0;i<vec.size();i++)
	{
		k[serch(vec[i])]=true;
	}
	int count=0;
	int ans=0;
	for(int i=1;i<=366;i++)
	{
		if(k[i])
		{
			count++;
			ans=max(ans,count);
		}
		else
		{
			count=0;
		}
	}
	cout << ans << endl;
	return 0;
}
