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
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 1<<17;
struct segtree
{
	int seg[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k)
	{
		seg[k]+=lazy[k];
		if(k<SIZE-1)
		{
			lazy[2*k+1]+=lazy[k];
			lazy[2*k+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update(int a,int b,int k,int l,int r,int x)
	{
		lazy_evaluate(k);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b)
		{
			lazy[k]+=x;
			lazy_evaluate(k);
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			seg[k] = max(seg[k*2+1],seg[k*2+2]);
			return;
		}
	}
	int query(int a,int b,int k,int l,int r)
	{
		lazy_evaluate(k);
		if(r<=a||b<=l)return 0;
		if(a<=l&&r<=b)return seg[k];
		else
		{
			int lch = query(a,b,k*2+1,l,(l+r)/2);
			int rch = query(a,b,k*2+2,(l+r)/2,r);
			return max(lch,rch);
		}
	}
	int value(int v){return seg[v]+lazy[v];}
	int get_index(int x)
	{
		int p=0;
		while(p<SIZE-1)
		{
			lazy_evaluate(p);
			if(value(2*p+1)>=x)p = p*2+1;
			else p = p*2+2;
		}
		return p-(SIZE-1);
	}
}seg;
int N,M;
struct obstacle
{
	int x,y,w;
	obstacle(int x,int y,int w):x(x),y(y),w(w){}
	bool operator < (const obstacle a) const
	{
		if(y!=a.y)return y < a.y;
		return x < a.x;
	}
};
int a[100100],ans_x[100100],ans_y[100100];
vector<int> weapon;
vector<obstacle> obs;
int main()
{
	scanf("%d %d",&N,&M);
	rep(i,N)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		obs.pb(obstacle(x,y,w));
	}
	sort(all(obs));
	rep(i,M)
	{
		scanf("%d",&a[i]);
		weapon.pb(a[i]);
	}
	sort(all(weapon));
	weapon.erase(unique(all(weapon)),weapon.end());
	memset(ans_x,-1,sizeof(ans_x));
	memset(ans_y,-1,sizeof(ans_y));
	int id = 0;
	rep(i,obs.size())
	{
		seg.update(obs[i].x,obs[i].x+obs[i].w,0,0,SIZE,1);
		int max_val = seg.query(0,SIZE,0,0,SIZE);
		while(id<M&&weapon[id]<max_val)
		{
			ans_y[id] = obs[i].y;
			ans_x[id] = seg.get_index(weapon[id]+1);
			id++;
		}
	}
	rep(i,M)
	{
		int k = lower_bound(all(weapon),a[i])-weapon.begin();
		printf("%d %d\n",ans_x[k],ans_y[k]);
	}
	return 0;
}