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
#define INF 100000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
const int DAT_SIZE=(1<<20)-1;
struct RMQ//Range Minimum (or Maximum) Query
{
	ll seg[DAT_SIZE];
	int seed;// 0:Minimum 1:Maxmum
	void init()
	{
		seed=0;
		if(seed)memset(seg,0,sizeof(seg));
		else for(int i=0;i<DAT_SIZE;i++)seg[i]=INF;
		return;
	}
	ll comp(ll a,ll b)
	{
		if(seed)return max(a,b);
		else return min(a,b);
	}
	void update(int k,ll x)
	{
		k+=DAT_SIZE/2;
		//seg[k]=x;
		seg[k]=comp(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=comp(seg[k*2+1],seg[k*2+2]);
		}
		return;
	}
	ll query(int a,int b,int k,int l,int r)
	{
		if(a>=r||b<=l)return seed?0:INF;
		else if(a<=l&&r<=b)return seg[k];
		else return comp(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
	ll query(int a,int b)
	{
		return query(a,b,0,0,(DAT_SIZE+1)/2);
	}
};
int N,L;
struct lamp
{
	int l,r,c;
	lamp(int l,int r,int c):l(l),r(r),c(c){}
};
bool comp(lamp a,lamp b){return a.l<b.l;}
vector<lamp> vec;
RMQ seg;
int main()
{
	scanf("%d %d",&N,&L);
	for(int i=0;i<N;i++)
	{
		int l,r,c;
		scanf("%d %d %d",&l,&r,&c);
		lamp n(l,r,c);
		vec.pb(n);
	}
	sort(vec.begin(),vec.end(),comp);
	seg.init();
	seg.update(0,0);
	for(int i=0;i<vec.size();i++)
	{
		ll mi=seg.query(vec[i].l,vec[i].r+1);
		seg.update(vec[i].r,mi+vec[i].c);
	}
	cout << seg.query(L,L+1) << endl;
	return 0;
}
