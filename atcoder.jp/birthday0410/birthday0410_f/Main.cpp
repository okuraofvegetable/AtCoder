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
bool prime[10005];
void eratos()
{
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i*i<=10000;i++)
	{
		if(!prime[i])continue;
		for(int j=i*2;j<10000;j+=i)
		{
			prime[j]=false;
		}
	}
	return;
}
int main()
{
	eratos();
	int cnt=0;
	vector<int> p;
	for(int i=2;i<1000000;i++)
	{
		if(prime[i])
		{
			p.pb(i);
			cnt++;
		}
		if(cnt==100)break;
	}
	vector<int> d;
	for(int i=0;i<p.size()-1;i++)d.pb(p[i+1]-p[i]);
	cout << "2";
	for(int i=0;i<99;i++)
	{
		printf("+%d*(n/%d-(n-1)/%d)",d[i],i+2,i+2);
	}
	cout << endl;
	return 0;
}
