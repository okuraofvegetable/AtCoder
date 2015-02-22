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
typedef pair<P,int> T;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int imos[10050],cnt[10050];
int a,b,n;
int p[5050],q[5050],r[5050],s[5050];
vector<int> vx,vy;
vector<T> event;
ll size(int x,int y)
{
	if(x+1>=(int)vx.size()||y+1>=(int)vy.size())return 0ll;
	return (ll)(vx[x+1]-vx[x])*(ll)(vy[y+1]-vy[y]);
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d",&a,&b);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&p[i],&q[i],&r[i],&s[i]);
		p[i]--;q[i]--;
		vx.pb(p[i]);vy.pb(q[i]);vx.pb(r[i]);vy.pb(s[i]);
	}
	sort(all(vx));
	sort(all(vy));
	vx.erase(unique(all(vx)),vx.end());
	vy.erase(unique(all(vy)),vy.end());
	for(int i=0;i<n;i++)
	{
		p[i]=lower_bound(all(vx),p[i])-vx.begin();
		q[i]=lower_bound(all(vy),q[i])-vy.begin();
		r[i]=lower_bound(all(vx),r[i])-vx.begin();
		s[i]=lower_bound(all(vy),s[i])-vy.begin();
		//printf("%d %d %d %d\n",p[i],q[i],r[i],s[i]);
		event.pb(T(P(p[i],q[i]),1));
		event.pb(T(P(p[i],s[i]),-1));
		event.pb(T(P(r[i],q[i]),-1));
		event.pb(T(P(r[i],s[i]),1));
	}
	sort(all(event));
	int SX = vx.size(),SY = vy.size();
	int id = 0;
	int ans_sz = 0;
	ll ans_num = 0ll;
	for(int i=0;i<=SX;i++)
	{
		if(!(id<event.size()))break;
		if(event[id].fi.fi!=i)continue;//kaizenpoint
		memset(cnt,0,sizeof(cnt));
		while(id<event.size()&&event[id].fi.fi==i)
		{
			cnt[event[id].fi.sec]+=event[id].sec;
			id++;
		}
		for(int j=0;j<=SY;j++)cnt[j+1]+=cnt[j];
		for(int j=0;j<=SY;j++)
		{
			imos[j]+=cnt[j];
			if(ans_sz<imos[j])
			{
				ans_sz = imos[j];
				ans_num = size(i,j);
			}
			else if(ans_sz==imos[j])
			{
				ans_num += size(i,j);
			}
		}
	}
	/*for(int i=0;i<=SX;i++)
	{
		for(int j=0;j<=SY;j++)
		{
			imos[i][j+1]+=imos[i][j];
		}
	}
	for(int j=0;j<=SX;j++)
	{
		for(int i=0;i<=SY;i++)
		{
			imos[i+1][j]+=imos[i][j];
		}
	}
	for(int i=0;i<=SX;i++)
	{
		for(int j=0;j<=SY;j++)
		{
			if(size(i,j)==0ll)break;
			if(ans_sz<imos[i][j])
			{
				ans_sz = imos[i][j];
				ans_num = size(i,j);
			}
			else if(ans_sz==imos[i][j])
			{
				ans_num += size(i,j);
			}
		}
	}*/
	printf("%d\n",ans_sz);
	printf("%lld\n",ans_num);
	return 0;
}
