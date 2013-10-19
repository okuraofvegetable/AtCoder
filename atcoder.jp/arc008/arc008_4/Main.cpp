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
typedef pair<double,double> P;
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
#define MAX_DAT_SZ (1<<18)-1
ll n;
int m;
int n_=1;
double data[MAX_DAT_SZ],datb[MAX_DAT_SZ];
map<ll,int> ma;
set<ll> s;
ll q[100100];
P query[100100];
double mi=1.0,mx=1.0;
int compress()
{
	int k=0;
	set<ll>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		if(ma.find(*it)==ma.end())ma[*it]=k++;
	}
	return s.size();
}
void init(int n)
{
	while(n_<n)n_*=2;
	for(int i=0;i<n_*2-1;i++)
	{
		data[i]=1.0;
		datb[i]=0.0;
	}
	return;
}
void update(int k,P x)
{
	k+=n_-1;
	data[k]=x.fi;datb[k]=x.sec;
	while(k>0)
	{
		k=(k-1)/2;
		data[k]=data[k*2+1]*data[k*2+2];
		datb[k]=datb[k*2+1]*data[k*2+2]+datb[k*2+2];
	}
	return;
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		cin >> q[i] >> query[i].fi >> query[i].sec;
		q[i]--;
		s.insert(q[i]);
	}
	init(compress());
	for(int i=0;i<m;i++)
	{
		update(ma[q[i]],query[i]);
		mi=min(mi,data[0]+datb[0]);
		mx=max(mx,data[0]+datb[0]);
	}
	printf("%.6f\n%.6f\n",mi,mx);
	return 0;
}
