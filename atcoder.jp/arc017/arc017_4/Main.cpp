#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SIZE=1<<19;
struct node
{
	ll gcd,left,right,lazy;
	node(ll gcd=0ll,ll left=0ll,ll right=0ll,ll lazy=0ll):gcd(gcd),left(left),right(right),lazy(lazy){}
};
struct segtree
{
	node seg[SIZE*2];
	segtree()
	{
		for(int i=0;i<SIZE*2;i++)seg[i]=node();
	}
	void init(int k,ll x)
	{
		k+=SIZE-1;
		seg[k].left=x;
		seg[k].right=x;
	}
	void build()
	{
		for(int k=SIZE-2;k>=0;k--)seg[k]=update(seg[k*2+1],seg[k*2+2]);
	}
	inline void lazy_evaluate(int k)
	{
		seg[k].left+=seg[k].lazy;
		seg[k].right+=seg[k].lazy;
		if(k<SIZE-1)
		{
			seg[k*2+1].lazy+=seg[k].lazy;
			seg[k*2+2].lazy+=seg[k].lazy;
		}
		seg[k].lazy=0ll;
	}
	inline node update(node a,node b)
	{
		node par;
		par.left=a.left;
		par.right=b.right;
		par.gcd=__gcd(__gcd(a.gcd,b.gcd),abs(b.left-a.right));
		return par;
	}
	void add(int a,int b,ll x,int k=0,int l=0,int r=SIZE)
	{
		lazy_evaluate(k);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b)
		{
			seg[k].lazy+=x;
			lazy_evaluate(k);
			return;
		}
		add(a,b,x,k*2+1,l,(l+r)/2);
		add(a,b,x,k*2+2,(l+r)/2,r);
		seg[k]=update(seg[k*2+1],seg[k*2+2]);
		return;
	}
	node query(int a,int b,int k=0,int l=0,int r=SIZE)
	{
		lazy_evaluate(k);
		if(r<=a||b<=l)return node();
		else if(a<=l&&r<=b)return seg[k];
		node left=query(a,b,k*2+1,l,(l+r)/2);
		node right=query(a,b,k*2+2,(l+r)/2,r);
		seg[k]=update(seg[k*2+1],seg[k*2+2]);
		return update(left,right);
	}
	ll ans(int a,int b)
	{
		node ans=query(a,b);
		return __gcd(ans.gcd,abs(ans.left));
	}
};
segtree seg;
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll k;
		scanf("%lld",&k);
		seg.init(i,k);
	}
	seg.build();
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int t,l,r;
		scanf("%d %d %d",&t,&l,&r);
		l--;
		if(t==0)printf("%lld\n",seg.ans(l,r));
		else seg.add(l,r,t);
	}
	return 0;
}
