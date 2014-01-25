#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> T;
#define mp make_pair
#define pb push_back
#define fi first
#define sec second
const int SIZE=(1<<19);
vector<int> x,y,dist;
vector<T> events;
int m,n,k;
ll ans;
struct segtree
{
	int seg[SIZE*2],lazy[SIZE*2];
	segtree()
	{
		memset(seg,0,sizeof(seg));
		memset(lazy,0,sizeof(lazy));
	}
	inline void lazy_evaluate(int k,int l,int r)
	{
		if(lazy[k])seg[k]=(x[r]-x[l])-seg[k];
		if(k<SIZE-1)
		{
			lazy[k*2+1]^=lazy[k];
			lazy[k*2+2]^=lazy[k];
		}
		lazy[k]=0;
	}
	int update(int a,int b,int k,int l,int r)
	{
		lazy_evaluate(k,l,r);
		if(a>=r||b<=l)return seg[k];
		else if(a<=l&&r<=b)
		{
			lazy[k]^=1;
			lazy_evaluate(k,l,r);
			return seg[k];
		}
		else return seg[k]=update(a,b,k*2+1,l,(l+r)/2)+update(a,b,k*2+2,(l+r)/2,r);
	}
	int get()
	{
		return seg[0];
	}
};
segtree seg;
int main()
{
	scanf("%d %d %d",&m,&n,&k);
	ans=(ll)n*m;
	for(int i=0;i<k;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		events.pb(mp(a,mp(c,d+1)));
		events.pb(mp(b+1,mp(c,d+1)));
		x.pb(c);x.pb(d+1);
	}
	x.pb(0);x.pb(m+1);
	sort(x.begin(),x.end());
	sort(events.begin(),events.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	for(int i=0;i<k*2;i++)
	{
		int a=lower_bound(x.begin(),x.end(),events[i].sec.fi)-x.begin();
		int b=lower_bound(x.begin(),x.end(),events[i].sec.sec)-x.begin();
		events[i].sec.fi=a;
		events[i].sec.sec=b;
		if(i>=1)dist.pb(events[i].fi-events[i-1].fi);
	}
	dist.pb(m+1-events[k*2-1].fi);
	seg.update(events[0].sec.fi,events[0].sec.sec,0,0,SIZE);
	for(int i=1;i<k*2;i++)
	{
		ans-=(ll)seg.get()*(ll)dist[i-1];
		seg.update(events[i].sec.fi,events[i].sec.sec,0,0,SIZE);
	}
	printf("%lld\n",ans);
	return 0;
}
